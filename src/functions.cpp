#include "../include/header.hpp"


void SortByName(std::vector<Student>& vector){
    Student bufer;
    bool flag{true};
    while(flag){
        flag = false;
        for(int i{1}; i<vector.size(); ++i){
            
            if(vector.at(i-1).Name > vector.at(i).Name){
                flag = true;
                bufer = vector.at(i-1);
                vector.at(i-1) = vector.at(i);
                vector.at(i) = bufer;
            }
        }
    }
}

float CountAverage(std::vector<unsigned>& vector){
    float summ{};
    for(auto i: vector) summ += i;
    return summ / vector.size();
}

void SortByRating(std::vector<Student>& vector){
    Student bufer;
    bool flag{true};
    while(flag){
        flag = false;
        for(int i{1}; i<vector.size(); ++i){
            if(CountAverage(vector.at(i-1).Ratings) < CountAverage(vector.at(i).Ratings)){
                flag = true;
                bufer = vector.at(i-1);
                vector.at(i-1) = vector.at(i);
                vector.at(i) = bufer;
            }
        }
    }
}

size_t CountTwoness(const std::vector<Student>& vector){
    size_t result{0};
    for(auto student: vector){
        for(auto rating:student.Ratings){
            if(rating <= 2){
                result += 1;
                break;
            }
        }
    }
    return result;
}

size_t CountExcellent(const std::vector<Student>& vector){
    size_t result{};
    for(auto student: vector){
        bool is_exelent{true};
        for(auto rating: student.Ratings){
            if(rating < 5){
                is_exelent = false;
                break;
            }
        }
        if(is_exelent) result += 1;
    }
    return result;
}

std::vector<Student> VectorMathExcellent(const std::vector<Student>& vector){
    std::vector<Student> result;
    for(auto student: vector){
        int index_math{-1};
        for(int i{}; i < student.Subjects.size(); ++i){
            if(student.Subjects.at(i) == "Math"){
                index_math = i;
                break;
            }
        }
        if(index_math == -1) continue;
        if(student.Ratings.at(index_math) == 5) result.push_back(student);
    }
    return result;
}

std::vector<std::string> GroupsId(const std::vector<Student>& vector){
    std::vector<std::string> result;
    for(auto student: vector){
        bool is_in_result = false;
        for(auto group_name:result){
            if(student.GroupId == group_name){
                is_in_result = true;
                break;
            }
        }
        if(!is_in_result) result.push_back(student.GroupId);
    }
    return result;
}

std::vector<Group> Groups(const std::vector<Student>& vector){
    std::vector<Group> result;
    for(auto student: vector){
        bool is_added{false};
        for(int i{}; i < result.size(); ++i){
            if(result.at(i).Id == student.GroupId){
                result.at(i).Students.push_back(student);
                is_added = true;
                break;
            }
        }
        if(!is_added){
            Group group = {student.GroupId, {student}};
            result.push_back(group);
        }
    }
    return result;
}


