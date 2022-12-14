/* File: makanan.h */
/* Definisi ADT Food (Makanan) */

#ifndef FOOD_H
#define FOOD_H

#include "../cstring/cstring.h"
#include "../point/point.h"
#include "../time/time.h"
#include "boolean.h"

/* *** Definisi enum Action *** */
enum Action { BUY, MIX, CHOP, FRY, BOIL };
/* enum Action dengan anggota berupa aksi yang harus dilakukan pada food */

static char* ActionName[] = { "Buy", "Mix", "Chop", "Fry", "Boil" };
/* representasi nilai enum Action dalam bentuk String */

/********************************/

typedef struct Size {
    int width;
    int height;
} Size;

/* *** Definisi TYPE Food *** */
typedef struct {
    int id;                 /* id food */
    String name;            /* nama food */
    Time expiration_time;   /* lama ekspirasi food */
    enum Action action_loc; /* aksi yang harus dilakukan pada food */
    Time delivery_time;     /* lama pengiriman food */
    Size size;              /* ukuran food */
    Time processing_time;   // waktu pengolahan makanan
} Food;

/********************************/

/* *** Notasi Akses: selektor Makanan *** */
// return int
#define Id(F) (F).id
// return String
#define Name(F) (F).name
// return Time
#define ExpirationTime(F) (F).expiration_time
// return enum Action | int
#define ActionLocation(F) (F).action_loc
// return Time
#define DeliveryTime(F) (F).delivery_time
// return size
#define Size(F) (F).size
// return processing_time
#define ProcTime(F) (F).processing_time

/* *** Konstruktor: Membentuk food dengan berbagai komponen sebagai properties-nya *** */
void CreateFood(Food* F,
                int id,
                String name,
                Time expiration_time,
                enum Action action_loc,
                Time delivery_time,
                Size size,
                Time processing_time);
/* I.S. semua parameter terdefinisi */
/* F.S. Terbentuk food dengan properties terdefinisi */

/* *** Debug: Menampilkan Food beserta properties-nya ****/
void DisplayFood(Food F);

#endif
