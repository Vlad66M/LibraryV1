#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include"BooksCollection.h"
#include"AuthorsCollection.h"
#include"BookRecordsCollection.h"
#include"TicketsCollection.h"
#include"ReadersCollection.h"

extern Model::BooksCollection* books;
extern Model::AuthorsCollection* authors;
extern Model::BookRecordsCollection* bookRecords;
extern Model::TicketsCollection* tickets;
extern Model::ReadersCollection* readers;


#endif // !GLOBAL_H
