// BookBastion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <limits>
#include <chrono>
using namespace std::chrono;

void bookDataImport(std::map<int, std::vector<std::string>>& order, std::unordered_map<int, std::vector<std::string>> & unOrder, std::unordered_map<std::string, std::vector<std::string>>& unOrder_titles, std::unordered_map<std::string, std::vector<std::string>>& unOrder_authors, std::map<std::string, std::vector<std::string>> & order_titles, std::map<std::string, std::vector<std::string>> & order_authors, std::map<std::string, int> & genreList) {
    std::ifstream infile("books_data.csv");
    std::string line;

    int index = 0;
    std::string title;
    std::string description;
    std::string author;
    std::string image;
    std::string preview;
    std::string publisher;
    std::string publishDate;
    std::string infoLink;
    std::string genre;
    std::string rating;

    while (std::getline(infile, line))
    {
        if (index != 0) {
            std::vector<std::string> data;
            std::vector<std::string> data_titles;
            std::vector<std::string> data_authors;

            size_t title1 = line.find("-0-", 0);
            size_t author1 = line.find("['", 0);    
            size_t author2 = line.find("']", 0);  
            size_t image1 = line.find("http", 0);
            size_t preview1 = line.find("http", image1 + 1);
            size_t publisher1 = line.find("-1-", preview1);
            size_t publisher2 = line.find("-0-", preview1);
            size_t info1 = line.find("http", publisher1);
            size_t genre1 = line.find("['", info1);
            size_t genre2 = line.find("']", genre1);
            size_t seperator = line.find("---", genre2);

            //cout << "Line: " << line << endl;

            title = line.substr(0, title1);         
            description = line.substr(title1 + 4, author1 - title1 - 5);
            author = line.substr(author1 + 2, author2 - author1 - 2);
            image = line.substr(image1, preview1 - image1  - 1);                 //fix
            preview = line.substr(preview1, publisher1 - preview1 - 1);         //fix
            publisher = line.substr(publisher1 + 3, publisher2 -  publisher1 - 3); //fix
            publishDate = line.substr(publisher2 + 4, info1 - publisher2 -  5);
            infoLink = line.substr(info1, genre1 - info1 - 1);
            genre = line.substr(genre1 + 2, genre2 - genre1 - 2);
            rating = line.substr(genre2 + 3, seperator - genre2 - 4);
            
            //normal
            data.push_back(title);
            data.push_back(description);
            data.push_back(author);

            data.push_back(image);
            data.push_back(preview);
            data.push_back(publisher);
            data.push_back(publishDate);
            data.push_back(infoLink);

            data.push_back(genre);
            data.push_back(rating);

            //titles - unorder
            data_titles.push_back(std::to_string(index));
            data_titles.push_back(description);
            data_titles.push_back(author);

            data_titles.push_back(image);
            data_titles.push_back(preview);
            data_titles.push_back(publisher);
            data_titles.push_back(publishDate);
            data_titles.push_back(infoLink);

            data_titles.push_back(genre);
            data_titles.push_back(rating);

            //authors - unorder
            data_authors.push_back(title);
            data_authors.push_back(description);
            data_authors.push_back(std::to_string(index));

            data_authors.push_back(image);
            data_authors.push_back(preview);
            data_authors.push_back(publisher);
            data_authors.push_back(publishDate);
            data_authors.push_back(infoLink);

            data_authors.push_back(genre);
            data_authors.push_back(rating);
            
            order.insert({ index, data });
            unOrder.insert({ index, data });
            order_titles.insert({ title, data_titles });
            order_authors.insert({ author, data_authors });
            unOrder_titles.insert({ title, data_titles });
            unOrder_authors.insert({ author, data_authors });
            if (genre.length() < 50) {
                genreList.insert({ genre, 0 });
            }
            data.clear();
        }
        index++;
    }

}

void bookRatingsImport() {
    //no success
}

//stack
bool is_digits(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

//filtered search
void orderedSearch(std::map<int, std::vector<std::string>>& order, std::string value, int rating1, int rating2, int yearRange1, int yearRange2, int opt1, int opt2, int opt3) {

    std::map<int, std::vector<std::string>>::iterator it = order.begin();

    std::vector<std::vector<std::string>> array;
    std::vector<std::string> array2;
    int count = 0;
    auto start = high_resolution_clock::now();
    while (it != order.end())
    {
        std::string storage;
        //genre
        if (opt1 == 1) {
            storage = it->second[8];
            transform(value.begin(), value.end(), value.begin(), ::toupper);
            transform(storage.begin(), storage.end(), storage.begin(), ::toupper);
        }
        //year
        int year = -1;
        if (opt2 == 1) {
            std::string helper = it->second[6];
            //includes month and year
            if (helper.length() > 4) {
                for (int i = 0; i < helper.length() - 5; i++) {
                    std::string helper2 = helper.substr(i, 4);
                    //std::cout << helper2 << std::endl;
                    if (is_digits(helper2) == true) {
                        helper = helper2;
                        //std::cout << "Year: " << helper << std::endl;
                        year = stoi(helper);
                        break;
                    }
                }
            }
            
        }
        //rating
        int rating = 0;
        if (opt3 == 1) {
            if (is_digits(it->second[9]) == true) {
                rating = stoi(it->second[9]);
            }
            else {
                rating = 0;
            }
        }
            
            //rating figure out the ratings csv 
            
            if (opt1 == 1 && opt2 == 1 && opt3 == 1) {
                if (storage.find(value) != std::string::npos) {
                    if (yearRange1 <= year && year <= yearRange2) {
                        if (rating1 <= rating && rating <= rating2) {
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                        }
                    }
                }
            }

            if (opt1 == 1 && opt2 == 1 && opt3 == 0) {
                if (storage.find(value) != std::string::npos) {
                    if (yearRange1 <= year && year <= yearRange2) {
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                    }
                }
            }

            if (opt1 == 1 && opt2 == 0 && opt3 == 1) {
                if (storage.find(value) != std::string::npos) {
                        if (rating1 <= rating && rating <= rating2) {
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                        }                
                }
            }

            if (opt1 == 1 && opt2 == 0 && opt3 == 0) {
                if (storage.find(value) != std::string::npos) {
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                }
            }

            if (opt1 == 0 && opt2 == 1 && opt3 == 1) {
                    if (yearRange1 <= year && year <= yearRange2) {
                        if (rating1 <= rating && rating <= rating2) {
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                        }
                    }
            }

            if (opt1 == 0 && opt2 == 1 && opt3 == 0) {
                    if (yearRange1 <= year && year <= yearRange2) {
                        //std::cout << yearRange1 << " " << year << " " << yearRange2 << std::endl;
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                    }
            }

            if (opt1 == 0 && opt2 == 0 && opt3 == 1) {
                        if (rating1 <= rating && rating <= rating2) {
                            count++;
                            array2.push_back(std::to_string(count));
                            array2.push_back(it->second[0]);
                            array2.push_back(it->second[2]);
                            array2.push_back(std::to_string(it->first));
                            array.push_back(array2);
                            array2.clear();
                        }
            }
            
           
        it++;
    }
    auto stop = high_resolution_clock::now();
    
    int count1 = 1;

    for (int i = 0; i < array.size(); i++){
        count1++;
        std::cout << array[i][0] << ". " << array[i][1] << " by " << array[i][2] << std::endl;
    }
    std::cout << count1 << ". Exit search." << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time for general search: " << duration.count() << std::endl;
    std::cout << "Input a book number for more data or select exit: " << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice == count1) {
        return;
    }
    else {
        if (choice <= 0) {
            std::cout << "Invalid option." << std::endl;
            return;
        }
        else {
            int temp = stoi(array[choice - 1][3]);
            auto start1 = high_resolution_clock::now();
            auto itr = order.find(temp);
            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            std::cout << "Time for final search: " << duration1.count() << std::endl;

            std::cout << "Title: " << itr->second[0] << std::endl;
            std::cout << "Author: " << itr->second[2] << std::endl;
            std::cout << "Description: " << itr->second[1] << std::endl;
            std::cout << "Publisher: " << itr->second[5] << std::endl;
            std::cout << "Published Date: " << itr->second[6] << std::endl;
            std::cout << "Genre: " << itr->second[8] << std::endl;
            if (stoi(itr->second[9]) == -1) {
                std::cout << "Ratings Amount: 0" << std::endl;
            }
            else {
                std::cout << "Ratings Amount: " << itr->second[9] << std::endl;
            }
            
            
        }
    }
}
//filtered search
void unorderedSearch(std::unordered_map<int, std::vector<std::string>>& unOrder, std::string value, int rating1, int rating2, int yearRange1, int yearRange2, int opt1, int opt2, int opt3) {
    
    std::unordered_map<int, std::vector<std::string>>::iterator it = unOrder.begin();

    std::vector<std::vector<std::string>> array;
    std::vector<std::string> array2;
    int count = 0;
    auto start = high_resolution_clock::now();
    while (it != unOrder.end())
    {
        std::string storage;
        //genre
        if (opt1 == 1) {
            storage = it->second[8];
            transform(value.begin(), value.end(), value.begin(), ::toupper);
            transform(storage.begin(), storage.end(), storage.begin(), ::toupper);
        }
        //year
        int year = -1;
        if (opt2 == 1) {
            std::string helper = it->second[6];
            //includes month and year
            if (helper.length() > 4) {
                for (int i = 0; i < helper.length() - 5; i++) {
                    std::string helper2 = helper.substr(i, 4);
                    //std::cout << helper2 << std::endl;
                    if (is_digits(helper2) == true) {
                        helper = helper2;
                        //std::cout << "Year: " << helper << std::endl;
                        year = stoi(helper);
                        break;
                    }
                }
            }

        }
        //rating
        int rating = 0;
        if (opt3 == 1) {
            if (is_digits(it->second[9]) == true) {
                rating = stoi(it->second[9]);
            }
            else {
                rating = 0;
            }
        }

        //rating figure out the ratings csv 

        if (opt1 == 1 && opt2 == 1 && opt3 == 1) {
            if (storage.find(value) != std::string::npos) {
                if (yearRange1 <= year && year <= yearRange2) {
                    if (rating1 <= rating && rating <= rating2) {
                        count++;
                        array2.push_back(std::to_string(count));
                        array2.push_back(it->second[0]);
                        array2.push_back(it->second[2]);
                        array2.push_back(std::to_string(it->first));
                        array.push_back(array2);
                        array2.clear();
                    }
                }
            }
        }

        if (opt1 == 1 && opt2 == 1 && opt3 == 0) {
            if (storage.find(value) != std::string::npos) {
                if (yearRange1 <= year && year <= yearRange2) {
                    count++;
                    array2.push_back(std::to_string(count));
                    array2.push_back(it->second[0]);
                    array2.push_back(it->second[2]);
                    array2.push_back(std::to_string(it->first));
                    array.push_back(array2);
                    array2.clear();
                }
            }
        }

        if (opt1 == 1 && opt2 == 0 && opt3 == 1) {
            if (storage.find(value) != std::string::npos) {
                if (rating1 <= rating && rating <= rating2) {
                    count++;
                    array2.push_back(std::to_string(count));
                    array2.push_back(it->second[0]);
                    array2.push_back(it->second[2]);
                    array2.push_back(std::to_string(it->first));
                    array.push_back(array2);
                    array2.clear();
                }
            }
        }

        if (opt1 == 1 && opt2 == 0 && opt3 == 0) {
            if (storage.find(value) != std::string::npos) {
                count++;
                array2.push_back(std::to_string(count));
                array2.push_back(it->second[0]);
                array2.push_back(it->second[2]);
                array2.push_back(std::to_string(it->first));
                array.push_back(array2);
                array2.clear();
            }
        }

        if (opt1 == 0 && opt2 == 1 && opt3 == 1) {
            if (yearRange1 <= year && year <= yearRange2) {
                if (rating1 <= rating && rating <= rating2) {
                    count++;
                    array2.push_back(std::to_string(count));
                    array2.push_back(it->second[0]);
                    array2.push_back(it->second[2]);
                    array2.push_back(std::to_string(it->first));
                    array.push_back(array2);
                    array2.clear();
                }
            }
        }

        if (opt1 == 0 && opt2 == 1 && opt3 == 0) {
            if (yearRange1 <= year && year <= yearRange2) {
                //std::cout << yearRange1 << " " << year << " " << yearRange2 << std::endl;
                count++;
                array2.push_back(std::to_string(count));
                array2.push_back(it->second[0]);
                array2.push_back(it->second[2]);
                array2.push_back(std::to_string(it->first));
                array.push_back(array2);
                array2.clear();
            }
        }

        if (opt1 == 0 && opt2 == 0 && opt3 == 1) {
            if (rating1 <= rating && rating <= rating2) {
                count++;
                array2.push_back(std::to_string(count));
                array2.push_back(it->second[0]);
                array2.push_back(it->second[2]);
                array2.push_back(std::to_string(it->first));
                array.push_back(array2);
                array2.clear();
            }
        }


        it++;
    }
    auto stop = high_resolution_clock::now();

    int count1 = 1;

    for (int i = 0; i < array.size(); i++) {
        count1++;
        std::cout << array[i][0] << ". " << array[i][1] << " by " << array[i][2] << std::endl;
    }
    std::cout << count1 << ". Exit search." << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time for general search: " << duration.count() << std::endl;
    std::cout << "Input a book number for more data or select exit: " << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice == count1) {
        return;
    }
    else {
        if (choice <= 0) {
            std::cout << "Invalid option." << std::endl;
            return;
        }
        else {
            int temp = stoi(array[choice - 1][3]);
            auto start1 = high_resolution_clock::now();
            auto itr = unOrder.find(temp);
            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            std::cout << "Time for final search: " << duration1.count() << std::endl;

            std::cout << "Title: " << itr->second[0] << std::endl;
            std::cout << "Author: " << itr->second[2] << std::endl;
            std::cout << "Description: " << itr->second[1] << std::endl;
            std::cout << "Publisher: " << itr->second[5] << std::endl;
            std::cout << "Published Date: " << itr->second[6] << std::endl;
            std::cout << "Genre: " << itr->second[8] << std::endl;
            if (stoi(itr->second[9]) == -1) {
                std::cout << "Ratings Amount: 0" << std::endl;
            }
            else {
                std::cout << "Ratings Amount: " << itr->second[9] << std::endl;
            }

        }
    }
}

void orderedSearchTitle(std::map<std::string, std::vector<std::string >> &order_titles, std::string value) {

    std::map<std::string, std::vector<std::string >>::iterator it = order_titles.begin();

    std::vector<std::vector<std::string>> array;
    std::vector<std::string> array2;
    int count = 0;
    auto start = high_resolution_clock::now();
    while (it != order_titles.end())
    {
        //title
        std::string storage = it->first;
        std::transform(value.begin(), value.end(), value.begin(), ::toupper);
        std::transform(storage.begin(), storage.end(), storage.begin(), ::toupper);

        if (storage.find(value) != std::string::npos) {
            count++;
            //std::cout << "Index: " << it->second[0] << std::endl;
            //std::cout << "Title: " << it->first << " Author: " << it->second[2] << std::endl;
            array2.push_back(std::to_string(count));
            array2.push_back(it->first);
            array2.push_back(it->second[2]);
            array2.push_back(it->second[0]);
            array.push_back(array2);
            //cout << count << endl;
            array2.clear();
        }
        it++;
    }
    auto stop = high_resolution_clock::now();
    int count1 = 1;

    for (int i = 0; i < array.size(); i++) {
        count1++;
        std::cout << array[i][0] << ". " << array[i][1] << " by " << array[i][2] << std::endl;
    }
    std::cout << count1 << ". Exit search." << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time for general search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Input a book number for more data or select exit: " << std::endl;

    int choice;
    std::cin >> choice;
    if (choice == count1) {
        return;
    }
    else {
        if (choice <= 0) {
            std::cout << "Invalid option." << std::endl;
            return;
        }
        else {
            std::string temp = array[choice - 1][1];
            auto start1 = high_resolution_clock::now();
            auto itr = order_titles.find(temp);
            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            std::cout << "Time for final search: " << duration1.count() << " microseconds" << std::endl;

            std::cout << "Title: " << itr->first << std::endl;
            std::cout << "Author: " << itr->second[2] << std::endl;
            std::cout << "Description: " << itr->second[1] << std::endl;
            std::cout << "Publisher: " << itr->second[5] << std::endl;
            std::cout << "Published Date: " << itr->second[6] << std::endl;
            std::cout << "Genre: " << itr->second[8] << std::endl;
            if (stoi(itr->second[9]) == -1) {
                std::cout << "Ratings Amount: 0" << std::endl;
            }
            else {
                std::cout << "Ratings Amount: " << itr->second[9] << std::endl;
            }


        }
    }
}

void orderedSearchAuthor(std::map<std::string, std::vector<std::string >>& order_titles, std::string value) {

    std::map<std::string, std::vector<std::string >>::iterator it = order_titles.begin();

    auto start = high_resolution_clock::now();
    std::vector<std::vector<std::string>> array;
    std::vector<std::string> array2;
    int count = 0;
    while (it != order_titles.end())
    {
        //title

        std::string storage = it->first;
        std::transform(value.begin(), value.end(), value.begin(), ::toupper);
        std::transform(storage.begin(), storage.end(), storage.begin(), ::toupper);

        if (storage.find(value) != std::string::npos) {
            count++;
            //std::cout << "Index: " << it->second[2] << std::endl;
            //std::cout << "Title: " << it->second[0] << " Author: " << it->first << std::endl;
            array2.push_back(std::to_string(count));
            array2.push_back(it->second[0]);
            array2.push_back(it->first);
            array2.push_back(it->second[2]);
            array.push_back(array2);
            array2.clear();
        }

        it++;
    }


    auto stop = high_resolution_clock::now();

    int count1 = 1;

    for (int i = 0; i < array.size(); i++) {
        count1++;
        std::cout << array[i][0] << ". " << array[i][1] << " by " << array[i][2] << std::endl;
    }
    std::cout << count1 << ". Exit search." << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time for general search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Input a book number for more data or select exit: " << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice == count1) {
        return;
    }
    else {
        if (choice <= 0) {
            std::cout << "Invalid option." << std::endl;
            return;
        }
        else {
            std::string temp = array[choice - 1][2];
            auto start1 = high_resolution_clock::now();
            auto itr = order_titles.find(temp);
            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            std::cout << "Time for final search: " << duration1.count() << " microseconds" << std::endl;

            std::cout << "Title: " << itr->second[0] << std::endl;
            std::cout << "Author: " << itr->first << std::endl;
            std::cout << "Description: " << itr->second[1] << std::endl;
            std::cout << "Publisher: " << itr->second[5] << std::endl;
            std::cout << "Published Date: " << itr->second[6] << std::endl;
            std::cout << "Genre: " << itr->second[8] << std::endl;
            if (stoi(itr->second[9]) == -1) {
                std::cout << "Ratings Amount: 0" << std::endl;
            }
            else {
                std::cout << "Ratings Amount: " << itr->second[9] << std::endl;
            }


        }
    }
}

void unorderedSearchTitle(std::unordered_map<std::string, std::vector<std::string>>& unOrder_titles, std::string value) {
    
    std::unordered_map<std::string, std::vector<std::string>>::iterator it = unOrder_titles.begin();

    std::vector<std::vector<std::string>> array;
    std::vector<std::string> array2;
    int count = 0;
    auto start = high_resolution_clock::now();
    while (it != unOrder_titles.end())
    {
        //title
            std::string storage = it->first;
            std::transform(value.begin(), value.end(), value.begin(), ::toupper);
            std::transform(storage.begin(), storage.end(), storage.begin(), ::toupper);

            if (storage.find(value) != std::string::npos) {
                count++;
                //std::cout << "Index: " << it->second[0] << std::endl;
                //std::cout << "Title: " << it->first << " Author: " << it->second[2] << std::endl;
                array2.push_back(std::to_string(count));
                array2.push_back(it->first);
                array2.push_back(it->second[2]);
                array2.push_back(it->second[0]);
                array.push_back(array2);
                //cout << count << endl;
                array2.clear();
            }
        it++;
    }
    auto stop = high_resolution_clock::now();
    int count1 = 1;

    for (int i = 0; i < array.size(); i++) {
        count1++;
        std::cout << array[i][0] << ". " << array[i][1] << " by " << array[i][2] << std::endl;
    }
    std::cout << count1 << ". Exit search." << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time for general search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Input a book number for more data or select exit: " << std::endl;

    int choice;
    std::cin >> choice;
    if (choice == count1) {
        return;
    }
    else {
        if (choice <= 0) {
            std::cout << "Invalid option." << std::endl;
            return;
        }
        else {
            std::string temp = array[choice - 1][1];
            auto start1 = high_resolution_clock::now();
            auto itr = unOrder_titles.find(temp);
            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            std::cout << "Time for final search: " << duration1.count() << " microseconds" << std::endl;

            std::cout << "Title: " << itr->first << std::endl;
            std::cout << "Author: " << itr->second[2] << std::endl;
            std::cout << "Description: " << itr->second[1] << std::endl;
            std::cout << "Publisher: " << itr->second[5] << std::endl;
            std::cout << "Published Date: " << itr->second[6] << std::endl;
            std::cout << "Genre: " << itr->second[8] << std::endl;
            if (stoi(itr->second[9]) == -1) {
                std::cout << "Ratings Amount: 0" << std::endl;
            }
            else {
                std::cout << "Ratings Amount: " << itr->second[9] << std::endl;
            }


        }
    }
}

void unorderedSearchAuthor(std::unordered_map<std::string, std::vector<std::string>>& unOrder_authors, std::string value) {

    std::unordered_map<std::string, std::vector<std::string>>::iterator it = unOrder_authors.begin();

    auto start = high_resolution_clock::now();
    std::vector<std::vector<std::string>> array;
    std::vector<std::string> array2;
    int count = 0;
    while (it != unOrder_authors.end())
    {
        //title
        
        std::string storage = it->first;
        std::transform(value.begin(), value.end(), value.begin(), ::toupper);
        std::transform(storage.begin(), storage.end(), storage.begin(), ::toupper);

            if (storage.find(value) != std::string::npos) {
                count++;
                //std::cout << "Index: " << it->second[2] << std::endl;
                //std::cout << "Title: " << it->second[0] << " Author: " << it->first << std::endl;
                array2.push_back(std::to_string(count));
                array2.push_back(it->second[0]);
                array2.push_back(it->first);
                array2.push_back(it->second[2]);
                array.push_back(array2);
                array2.clear();
            }

        it++;
    }
    

    auto stop = high_resolution_clock::now();

    int count1 = 1;

    for (int i = 0; i < array.size(); i++) {
        count1++;
        std::cout << array[i][0] << ". " << array[i][1] << " by " << array[i][2] << std::endl;
    }
    std::cout << count1 << ". Exit search." << std::endl;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time for general search: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Input a book number for more data or select exit: " << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice == count1) {
        choice = 0;
        return;
    }
    else {
        if (choice <= 0) {
            std::cout << "Invalid option." << std::endl;
            return;
        }
        else {
            std::string temp = array[choice - 1][2];
            auto start1 = high_resolution_clock::now();
            auto itr = unOrder_authors.find(temp);
            auto stop1 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            std::cout << "Time for final search: " << duration1.count() << " microseconds" << std::endl;

            std::cout << "Title: " << itr->second[0] << std::endl;
            std::cout << "Author: " << itr->first << std::endl;
            std::cout << "Description: " << itr->second[1] << std::endl;
            std::cout << "Publisher: " << itr->second[5] << std::endl;
            std::cout << "Published Date: " << itr->second[6] << std::endl;
            std::cout << "Genre: " << itr->second[8] << std::endl;
            if (stoi(itr->second[9]) == -1) {
                std::cout << "Ratings Amount: 0" << std::endl;
            }
            else {
                std::cout << "Ratings Amount: " << itr->second[9] << std::endl;
            }


        }
    }
}

int main()
{
    std::cout << "Welcome to Book Bastion!" << std::endl;
    std::cout << "--Initializing Data Structures--" << std::endl;

    //initialize both maps
    std::map<int, std::vector<std::string>> order;
    //similar to ordered
    std::unordered_map<int, std::vector<std::string>> unOrder;

    //titles as key
    std::map<std::string, std::vector<std::string>> order_titles;
    std::unordered_map<std::string, std::vector<std::string>> unOrder_titles;
    //author as key
    std::unordered_map<std::string, std::vector<std::string>> unOrder_authors;
    std::map<std::string, std::vector<std::string>> order_authors;

    //genre map
    std::map<std::string, int> genreList;

    //import data from sheets into both maps
    bookDataImport(order, unOrder, unOrder_titles, unOrder_authors, order_titles, order_authors, genreList);

    bool run = true;
    int helper = -1;
    while (run == true) {
        helper++;
        int design = 0;
        std::cout << "What data structure would you like to use?: " << std::endl;
        std::cout << "1. Ordered Map" << std::endl;
        std::cout << "2. Unordered Map" << std::endl;
        std::cout << "3. Exit the program" << std::endl;
        if (helper != 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::cin >> design;

        if (design == 1) {
            std::cout << "--Ordered Map Edition--" << std::endl;
            std::cout << "What would you like to search?" << std::endl;
            std::cout << "1. Title Name" << std::endl;
            std::cout << "2. Author Name" << std::endl;
            std::cout << "3. Advanced Search" << std::endl;
            int choice = 0;
            std::cin >> choice;

            if (choice == 1) {
                std::cout << "Input the title: " << std::endl;
                std::string value;
                std::cin >> value;
                orderedSearchTitle(order_titles, value);
            }
            else if (choice == 2) {
                std::cout << "Input the author: " << std::endl;
                std::string value;
                std::cin >> value;
                orderedSearchAuthor(order_authors, value);
            }
            else if (choice == 3) {
                std::cout << "The search will now be based on new parameters: " << std::endl;
                std::cout << "1. Genre" << std::endl;
                std::cout << "2. Rating(range)" << std::endl;
                std::cout << "3. Year(range)" << std::endl;

                std::cout << std::endl;
                int x = 0;
                int y = 0;
                int z = 0;

                int genreNum = 0;
                std::string genreVal;
                int year1 = 0;
                int year2 = 0;
                int rate1 = 0;
                int rate2 = 0;

                std::cout << "Do you want a genre filter? (Y or N):  " << std::endl;
                char genreChoice;
                std::cin >> genreChoice;

                if (genreChoice == 'Y' || genreChoice == 'y') {
                    x = 1;
                    int count = 0;
                    for (std::pair<std::string, int> it: genreList) {
                        count++;
                        std::cout <<count << ". " << it.first << std::endl;
                    }

                    std::cout << "Choose a genre by number: " << std::endl;
                    std::cin >> genreNum;

                    int count3 = 0;
                    for (std::pair<std::string, int> it : genreList) {
                        count3++;
                        if (genreNum == count3) {
                            genreVal = it.first;
                        }
                    }

                    //print out a list
                }

                std::cout << "Do you want a rating filter? This only for amount of ratings :( (Y or N):  " << std::endl;
                char ratingChoice;
                std::cin >> ratingChoice;

                if (ratingChoice == 'Y' || ratingChoice == 'y') {
                    z = 1;
                    //std::cout << "The ratings range from 0 - 5: " << std::endl;

                    std::cout << "Enter the minimum rating (integer): " << std::endl;
                    std::cin >> rate1;

                    std::cout << "Enter the maximum rating (integer): " << std::endl;
                    std::cin >> rate2;
                }

                std::cout << "Do you want a year filter? (Y or N):  " << std::endl;
                char yearChoice;
                std::cin >> yearChoice;

                if (yearChoice == 'Y' || yearChoice == 'y') {
                    y = 1;
                    std::cout << "Enter the minimum year (4 digits): " << std::endl;
                    std::cin >> year1;

                    std::cout << "Enter the maximum rating (4 digits): " << std::endl;
                    std::cin >> year2;
                }

                orderedSearch(order, genreVal, rate1, rate2, year1, year2, x, y, z);
            }
            else {
                std::cout << "Invalid input." << std::endl;
            }



        }
        else if (design == 2) {
            std::cout << "--Unordered Map Edition--" << std::endl;
            std::cout << "What would you like to search?" << std::endl;
            std::cout << "1. Title Name" << std::endl;
            std::cout << "2. Author Name" << std::endl;
            std::cout << "3. Advanced Search" << std::endl;

            int choice = 0;
            std::cin >> choice;

            if (choice == 1) {
                std::cout << "Input the title: " << std::endl;
                std::string value;
                std::cin >> value;
                unorderedSearchTitle(unOrder_titles, value);
            }
            else if (choice == 2) {
                std::cout << "Input the author: " << std::endl;
                std::string value;
                std::cin >> value;
                unorderedSearchAuthor(unOrder_authors, value);
            }
            else if (choice == 3) {
                std::cout << "The search will now be based on new parameters: " << std::endl;
                std::cout << "1. Genre" << std::endl;
                std::cout << "2. Rating(range)" << std::endl;
                std::cout << "3. Year(range)" << std::endl;

                std::cout << std::endl;
                int x = 0;
                int y = 0;
                int z = 0;

                int genreNum = 0;
                std::string genreVal;
                int year1 = 0;
                int year2 = 0;
                int rate1 = 0;
                int rate2 = 0;

                std::cout << "Do you want a genre filter? (Y or N):  " << std::endl;
                char genreChoice;
                std::cin >> genreChoice;

                if (genreChoice == 'Y' || genreChoice == 'y') {
                    x = 1;
                    
                    //print out a list
                    int counter1 = 0;
                    for (std::pair<std::string, int> it : genreList) {
                        counter1++;
                        std::cout << counter1 << ". " << it.first << std::endl;
                    }
                    std::cout << "Choose a genre by number: " << std::endl;
                    std::cin >> genreNum;
                    int count3 = 0;
                    for (std::pair<std::string, int> it : genreList) {
                        count3++;
                        if (genreNum == count3) {
                            genreVal = it.first;
                        }
                    }

                    
                }

                std::cout << "Do you want a rating filter? (Y or N):  " << std::endl;
                char ratingChoice;
                std::cin >> ratingChoice;

                if (ratingChoice == 'Y' || ratingChoice == 'y') {
                    z = 1;
                    //std::cout << "The ratings range from 0 - 5: " << std::endl;

                    std::cout << "Enter the minimum rating (integer): " << std::endl;
                    std::cin >> rate1;

                    std::cout << "Enter the maximum rating (integer): " << std::endl;
                    std::cin >> rate2;
                }

                std::cout << "Do you want a year filter? (Y or N):  " << std::endl;
                char yearChoice;
                std::cin >> yearChoice;

                if (yearChoice == 'Y' || yearChoice == 'y') {
                    y = 1;
                    std::cout << "Enter the year (Up to 4 digits): " << std::endl;
                    std::cin >> year1;

                    std::cout << "Enter the maximum year (4 digits): " << std::endl;
                    std::cin >> year2;
                }

                unorderedSearch(unOrder, genreVal, rate1, rate2, year1, year2, x, y, z);
            }
            else {
                std::cout << "Invalid input." << std::endl;
            }
        }
        else if (design == 3) {
            std::cout << "Thank you for using Book Bastion!" << std::endl;
            return 1;
        }
        else {
            std::cout << "That is not a valid choice." << std::endl;
        }

    }

    return 1;
}

