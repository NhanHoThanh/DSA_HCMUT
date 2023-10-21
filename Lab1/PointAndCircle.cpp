#include <bits/stdc++.h>
#include <string.h>

#include <iostream>

/*
int strLen(char* str) {
    if (*str == '\0') return 0;
    return 1 + strLen(str + 1);
}

string expand(string s) {
    ///
}
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
int findLCM(int a, int b) { return (a * b) / gcd(a, b); }
void printHailStone(int n) {
    cout << n << " ";
    if (n == 1) return;
    if (n % 2 == 0)
        printHailStone(n / 2);
    else
        printHailStone(3 * n + 1);
}
int mininumBracketAdd(string s, int i = 0, int count = 0, int open = 0) {
    if (i == static_cast<int>(s.length())) {
        return count + open;
    } else {
        if (s[i] == '(') {
            return mininumBracketAdd(s, i + 1, count, open + 1);
        } else {
            if (open > 0) {
                return mininumBracketAdd(s, i + 1, count, open - 1);
            } else {
                return mininumBracketAdd(s, i + 1, count + 1, open);
            }
        }
    }
}
string eliminateSpace(string s) {
    if (s.empty()) {
        return s;
    }
    if (s[0] == ' ') {
        return eliminateSpace(s.substr(1));
    } else {
        return s[0] + eliminateSpace(s.substr(1));
    }
}
bool isPalindrome(string s, int start = 0, int end = -1) {
    s = eliminateSpace(s);
    if (end == -1) {
        end = s.length() - 1;  // The length is one unit higher that the index
    }
    if (start == end) {
        return true;
    }
    if (s[start] != s[end]) {
        return false;
    }
    if (start < end) {
        return isPalindrome(s, start + 1, end - 1);
    }
}

int findMax(int* arr, int length) {

if (length == 1) {
    cout << "end: " << arr[0] << endl;
    return arr[0];
}
int max = findMax(arr + 1, length - 1);
cout << "Loop: " << max << endl;
if (arr[0] >= max)
    return arr[0];
else {
    return max;
}
}

void printPattern(int n) {

    if (n <= 0) {
        cout << n;
        return;
    }
    cout << n << ", ";
    printPattern(n - 5);
    cout << ", " << n;
}
void printArray(int n) {

    if (n == 0) {
        cout << n;
        return;
    }
    printArray(n - 1);
    cout << ", " << n;
}

*/

using namespace std;
class Point {
   private:
    double x, y;

   public:
    Point() {
        /*
         * STUDENT ANSWER
         * TODO: set zero x-y coordinate
         */
        x = 0;
        y = 0;
    }

    Point(double x, double y) {
        /*
         * STUDENT ANSWER
         */
        this->x = x;
        this->y = y;
    }

    void setX(double x) {
        /*
         * STUDENT ANSWER
         */
        this->x = x;
    }

    void setY(double y) {
        /*
         * STUDENT ANSWER
         */
        this->y = y;
    }

    double getX() const {
        /*
         * STUDENT ANSWER
         */
        return x;
    }

    double getY() const {
        /*
         * STUDENT ANSWER
         */
        return y;
    }

    double distanceToPoint(const Point& pointA) {
        /*
         * STUDENT ANSWER
         * TODO: calculate the distance from this point to point A in the
         * coordinate plane
         */
        return sqrt(pow(pointA.x - x, 2) + pow(pointA.y - y, 2));
    }
};

class Circle {
   private:
    Point center;
    double radius;

   public:
    Circle() {
        /*
         * STUDENT ANSWER
         * TODO: set zero center's x-y and radius
         */
        center.setX(0);
        center.setY(0);
    }

    Circle(Point center, double radius) {
        /*
         * STUDENT ANSWER
         */
        this->center.setX(center.getX());
        this->center.setY(center.getY());
        this->radius = radius;
    }

    Circle(const Circle& circle) {
        /*
         * STUDENT ANSWER
         */
        this->center.setX(circle.center.getX());
        this->center.setY(circle.center.getY());
        this->radius = circle.getRadius();
    }

    void setCenter(Point point) {
        /*
         * STUDENT ANSWER
         */
        this->center.setX(point.getX());
        this->center.setY(point.getY());
    }

    void setRadius(double radius) {
        /*
         * STUDENT ANSWER
         */
        this->radius = radius;
    }

    Point getCenter() const {
        /*
         * STUDENT ANSWER
         */
        return center;
    }

    double getRadius() const {
        /*
         * STUDENT ANSWER
         */
        return radius;
    }
    bool containsPoint(const Point point) {
        /*
         * STUDENT ANSWER
         * TODO: check if a given point is entirely within the circle (does not
         count if the point lies on the circle). If contain, return true.
         */
        return center.distanceToPoint(point) < radius;
    }

    bool containsTriangle(const Point pointA, const Point pointB,
                          const Point pointC) {
        /*
         * STUDENT ANSWER
         * TODO: check if a given triangle ABC (A, B, C are not on the same
         line) is entirely within the circle (does not count if any point of the
         triangle lies on the circle). If contain, return true.
         */
        return containsPoint(pointA) && containsPoint(pointB) &&
               containsPoint(pointC);
    }
    void operator=(const Circle& circle) {
        /*
         * STUDENT ANSWER
         */
        this->center.setX(circle.center.getX());
        this->center.setY(circle.center.getY());
        this->radius = circle.getRadius();
    }

    bool operator==(const Circle& circle) {
        /*
         * STUDENT ANSWER
         */
        return this->center.getX() == circle.center.getX() &&
               this->center.getY() == circle.center.getY() &&
               this->radius == circle.getRadius();
    }

    friend istream& operator>>(istream& in, Circle& circle) {
        /*
         * STUDENT ANSWER
         */
        double x, y, r;
        in >> x >> y >> r;
        circle.center.setX(x);
        circle.center.setY(y);
        circle.radius = r;
        return in;
    }
    void printCircle() {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(),
               this->center.getY(), this->radius);
    }
};

class Character {
   protected:
    int hp;
    int x;
    int y;

   public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);

    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
    // Operator =: copy all data from Character other
    void operator=(const Character& other);

    // Operator <: Character a < Character b when a's hp is less than or equal
    // b's hp
    bool operator<(const Character& other);

    // Operator () with zero parameters: print data of the instance with format:
    // hp-x-y
    void operator()();
};

Character::Character() {
    // STUDENT ANSWER

    this->x = 0;
    this->y = 0;
    this->hp = 0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    this->x = x;
    this->y = y;
    this->hp = hp;
}

int Character::getHp() {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
    // STUDENT ANSWER
    return this->y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    return abs(this->x - other->x) + abs(this->y - other->y);
}

// Copy all data from Character other
void Character::operator=(const Character& other) {
    // STUDENT ANSWER
    this->setX(other.x);
    this->setY(other.y);
    this->setHp(other.hp);
}

// Character a < Character b when a's hp is less than or equal b's hp
bool Character::operator<(const Character& other) {
    // STUDENT ANSWER
    return this->getHp() <= other.hp;
}

// Print data of the instance with format: hp-x-y
void Character::operator()() {
    // STUDENT ANSWER
    cout << this->hp << "-" << this->x << "-" << this->y;
}

class Player : public Character {
   public:
    Player() : Character() {}

    Player(int hp, int x, int y) : Character(hp, x, y) {}

    void printPlayerData() {
        cout << Character::getHp() << "-" << Character::getX() << "-"
             << Character::getY() << endl;
    }

    void moveTo(int x, int y) {
        Character::setX(x);
        Character::setY(y);
    }
};

class Book {
   private:
    string title;
    string authors;
    int publishingYear;

   public:
    Book() : publishingYear(0) {}

    Book(const string& title, const string& authors, int publishingYear)
        : title(title), authors(authors), publishingYear(publishingYear) {}

    Book(const Book& book)
        : title(book.title),
          authors(book.authors),
          publishingYear(book.publishingYear) {}

    void setTitle(const string& title) { this->title = title; }

    void setAuthors(const string& authors) { this->authors = authors; }

    void setPublishingYear(int publishingYear) {
        this->publishingYear = publishingYear;
    }

    string getTitle() const { return title; }

    string getAuthors() const { return authors; }

    int getPublishingYear() const { return publishingYear; }

    ~Book() {}

    friend bool checkAuthor(Book book, const string& author) {
        string authors = book.getAuthors();
        size_t pos = authors.find(author);
        if (pos != string::npos) {
            return true;
        }
        return false;
    }

    void printBook() {
        cout << title << endl << authors << endl << publishingYear << endl;
    }
    friend class Printer;
};

class Printer {
   public:
    static void printBook(const Book book) {
        cout << book.getTitle() << endl;
        string authors = book.getAuthors();
        size_t pos = 0;
        while (pos != string::npos) {
            size_t nextPos = authors.find(", ", pos);
            string currentAuthor = authors.substr(pos, nextPos - pos);
            cout << currentAuthor << endl;
            pos = nextPos;
            if (pos != string::npos) {
                pos += 2;  // skip ", "
            }
        }
        cout << book.getPublishingYear() << endl;
    }
};

enum Color { red, green, blue };
enum Size { small, medium, big };

class Toy {
   protected:
    double price;

   public:
    Toy(double price) { this->price = price; }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy {
   private:
    Color color;

   public:
    CarToy(double price, Color color) : Toy(price) {
        /*
         * STUDENT ANSWER
         */
        this->color = color;
    }

    void printType() { cout << "This is a car toy\n"; }

    friend class ToyBox;
};

class PuzzleToy : public Toy {
   private:
    Size size;

   public:
    PuzzleToy(double price, Size size) : Toy(price) {
        /*
         * STUDENT ANSWER
         */
        this->size = size;
    }

    void printType() { cout << "This is a puzzle toy\n"; }

    friend class ToyBox;
};

class ToyBox {
   private:
    Toy* toyBox[5];
    int numberOfItems;

   public:
    ToyBox() {
        /*
         * STUDENT ANSWER
         * TODO: set zero numberOfItems and nullptr toyBox
         */
        this->numberOfItems = 0;
        for (int i = 0; i < 5; i++) {
            toyBox[i] = nullptr;
        }
    }

    int addItem(const CarToy& carToy) {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Car toy to the box.
                 If successfully added, the function returns the current number
         of toys in the box. If the box is full, return -1.
         */

        if (numberOfItems >= 5) {
            return -1;  // box is full
        }
        toyBox[numberOfItems] = new CarToy(carToy);
        numberOfItems++;
        return numberOfItems;
    }

    int addItem(const PuzzleToy& puzzleToy) {
        /*
         * STUDENT ANSWER
         * TODO: function add a new Puzzle toy to the box.
                 If successfully added, the function returns the current number
         of toys in the box. If the box is full, return -1.
         */

        if (numberOfItems >= 5) {
            return -1;  // box is full
        }
        toyBox[numberOfItems] = new PuzzleToy(puzzleToy);
        numberOfItems++;
        return numberOfItems;
    }

    void printBox() {
        for (int i = 0; i < numberOfItems; i++) toyBox[i]->printType();
    }
};

int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);

    for (int i = 0; i < length; i++) {
        if (k < 0) {
            return i - 1;
        } else {
            k -= nums[i];
        }
    }
}

bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    if (nums.empty()) {
        return true;  // empty vector contains no non-consecutive 1s
    }
    bool foundOne = false;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (!foundOne) {
                foundOne = true;
            } else if (nums[i - 1] != 1) {
                return false;  // non-consecutive 1s found
            }
        }
    }
    return true;  // all 1s are consecutive
}

int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    int sumRight = 0;
    int sumLeft = 0;
    for (int i = 0; i < nums.size(); i++) {
        sumRight += nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
        sumRight -= nums[i];
        if (sumLeft == sumRight) {
            return i;
        }
        sumLeft += nums[i];
    }
    return -1;
}

vector<int> updateArrayPerRange(vector<int>& nums,
                                vector<vector<int>>& operations) {
    // STUDENT ANSWER
    int size = operations.size();
    for (int i = 0; i < size; i++) {
        for (int j = operations[i][0]; j <= operations[i][1]; j++) {
            nums[j] += operations[i][2];
        }
    }
    return nums;
}

template <class T>
class ArrayList {
   protected:
    T* data;  // dynamic array to store the list's items int capacity; // size
              // of the dynamic array int count; // number of items stored in
              // the array public: ArrayList(){capacity = 5; count = 0; data =
              // new T[5];} ~ArrayList(){ delete[] data; } void add(T e); void
              // add(int index, T e); int size(); void ensureCapacity(int
              // index); };

    template void ArrayList::ensureCapacity(
        int cap) { /* if cap == capacity: new_capacity = capacity * 1.5; create
                      new array with new_capacity else: do nothing */
    }

    template void ArrayList::add(
        T e) { /* Insert an element into the end of the array. */
    }

    template void ArrayList::add(
        int index, T e) { /* Insert an element into the array at given index. if
                             index is invalid: throw std::out_of_range("the
                             input index is out of range!"); */
    }

    template int ArrayList::size() { /* Return the length (size) of the array */
        return 0;
    }

    template <class T>
    void ArrayList<T>::ensureCapacity(int cap) {
        if (cap == capacity) {
            int new_capacity = capacity * 1.5;
            T* new_data = new T[new_capacity];
            for (int i = 0; i < count; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    template <class T>
    void ArrayList<T>::add(T e) {
        ensureCapacity(count);
        data[count] = e;
        count++;
    }

    template <class T>
    void ArrayList<T>::add(int index, T e) {
        if (index < 0 || index > count) {
            throw std::out_of_range("the input index is out of range!");
        }
        ensureCapacity(count);
        for (int i = count; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = e;
        count++;
    }

    template <class T>
    int ArrayList<T>::size() {
        return count;
    }

    template <class T>
    T ArrayList<T>::removeAt(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("index is out of range");
        }
        T removed = data[index];
        for (int i = index; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
        return removed;
    }

    template <class T>
    bool ArrayList<T>::removeItem(T item) {
        for (int i = 0; i < count; i++) {
            if (data[i] == item) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    template <class T>
    void ArrayList<T>::clear() {
        delete[] data;
        data = new T[5];
        capacity = 5;
        count = 0;
    }
};