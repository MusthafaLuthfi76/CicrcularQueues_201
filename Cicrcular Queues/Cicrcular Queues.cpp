#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queue_array[5];

public :
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a Number : ";
        cin >> num;
        cout << endl;

        //Cek Apakah Antrian Penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue Overflow\n";
            return;
        }

        //Cek apakah antrian kosong 
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            //Jika REAR berada di posisi terakhir Array, kembali ke awal Array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    void remove() {
        //cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "\nThe Element Deleted from The Queue is : " << queue_array[FRONT] << "\n";

        //Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            //Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        //Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElemen in the queu are ...\n";

        //Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            //Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            
            FRONT_position = 0;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
