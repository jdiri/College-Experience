/*
 Description: Prolog program with various queries and rules.
*/

/*
"Animals that are mammals have hair. If an animal has hair, it is warm-blooded." 
*/

/* Facts */
mammal(dog).
mammal(human).
mammal(dolphin).

/* Rules */
has_hair(X) :- mammal(X).
warm_blooded(X) :- has_hair(X).


/*
Prolog program for the following statements:
(1) A book is a best-seller if it has sold more than 100 million copies.
(2) The book 'The Da Vinci Code' has sold 80 million copies.
(3) The book 'Harry Potter and the Philosopher's Stone' has sold 120 million copies.
(4) A book is popular if it has sold more than 50 million copies.
(5) Anyone who has read a popular book is a book lover.
(6) Anyone who has read a best-seller is a book enthusiast.
(7) john has read the 'The Da Vinci Code'.
(8) jane has read the 'The Da Vinci Code' and 'Harry Potter and the Philosopher's Stone'
*/

/* Facts */
sold_copies('The Da Vinci Code', 80).
sold_copies('Harry Potter and the Philosopher\'s Stone', 120).
read_book(john, 'The Da Vinci Code').
read_book(jane, 'The Da Vinci Code').
read_book(jane, 'Harry Potter and the Philosopher\'s Stone').

/* Rules */
best_seller(Book) :- sold_copies(Book, Copies), Copies > 100.
popular(Book) :- sold_copies(Book, Copies), Copies > 50.
book_lover(Person) :- read_book(Person, Book), popular(Book).
book_enthusiast(Person) :- read_book(Person, Book), best_seller(Book).


/* Facts & Rules */
vegetarian(jose). 
vegetarian(james). 
vegetable(carrot). 
vegetable(egg_plant). 
likes(jose, X) :- vegetable(X). 
loves(Who, egg_plant) :- vegetarian(Who). 


/* Facts & Rules */
square(1,1).
square(2,4).
square(3,9).
square(N,R) :- N >= 4, N1 is N-1, square(N1,R1), R is R1 + (2*N) - 1.


/*
For the following English sentences, here are the applicable Prolog facts, rules:
a) John reads history book. 
b) A book is interesting if it has more than 200 pages.
c) The history book has 300 pages.
d) A person is a reader if they have read an interesting book.
e) Anyone is a fan of sparky if he/she is an ASU student. 
f) Mary is a UCLA student.
g) Is Mary a fan of sparky? 
h) Tempe is a small and crowded city.
i) Jane hates any city if it is small and crowded.
j) Does Jane hate Tempe?
*/

reads(john, history_book).
interesting_book(X) :- pages(X, N), N > 200.
pages(history_book, 300).
reader(X) :- reads(X, Y), interesting_book(Y).
asu_student(mary).
fan_of_sparky(X) :- asu_student(X).
ucla_student(mary).
small(_) :- true.
crowded(_) :- true.
city_tempe(small, crowded).
hates_city(X, Y) :- city_tempe(X, Y), small(X), crowded(X).


/*
Program that calculates the product of the first n natural numbers. 
For instance: 
?- product(3,X). → X=6
?- product(5,X). → X=120
?- product(7,X). → X=5040
*/

/* Facts and Rule to calculate the product of the first N natural numbers */
product(0,1).
product(N,Result) :-
  N > 0,
  N1 is N-1,
  product(N1,SubResult),
  Result is N*SubResult.
