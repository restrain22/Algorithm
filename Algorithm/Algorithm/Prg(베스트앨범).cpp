#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays);
bool compare1(pair<string, int> a, pair<string, int> b);
bool compare2(pair<int, int> a, pair<int, int> b);

//int main() {
//    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
//    vector<int> plays = { 500, 600, 150, 800, 2500 };
//    solution(genres, plays);
//}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> hash_genre;
    unordered_map<string, vector<pair<int,int>>> hash_music;
    
    int i = 0;
    for (string genre : genres) {
        hash_genre[genre] += plays[i];
        hash_music[genre].push_back(make_pair(i,plays[i]));
        i++;
    }
    
    vector<pair<string, int>> vec_genre;
    for (auto genre : hash_genre) {
        vec_genre.push_back(genre);
    }
    sort(vec_genre.begin(), vec_genre.end(),compare1);
    for (auto& music : hash_music) {
        sort(music.second.begin(), music.second.end(), compare2);
    }
    for (auto genre : vec_genre) {
        int i = 0;
        //cout << "genre : " << genre.first << endl;
        for (auto music : hash_music[genre.first]) {
           if (i >= 2) break;
            //cout << music.first<<" "<<music.second << endl;
            answer.push_back(music.first);
            i++;
        }
    }


    return answer;
}
bool compare1(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
bool compare2(pair<int, int> a, pair<int, int> b) {
    //cout << "a :" << a.first << "," << a.second << " , b : " << b.first << "," << b.second << endl;
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}