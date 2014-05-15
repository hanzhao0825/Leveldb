#include <iostream>
#include <stdlib.h>
#include <leveldb/db.h>
using namespace std;

int main(){
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "testdb", &db, "bbestdb/");
    char c1[100] = {0}, c2[100] = {0};
    for (int i = 0; i < 100000; i++){
        for (int j = 0; j < 80; j++){
            c1[j] = rand() % 20 + 100;
            c2[j] = rand() % 20 + 100;
        }
        db->Put(leveldb::WriteOptions(), string(c1), string(c2));
    }
}