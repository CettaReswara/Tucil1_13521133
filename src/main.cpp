#include <iostream>
#include <time.h>
#include "ascii.cpp"
#include "solve24.cpp"
#include "io.cpp"

using namespace std;

int main() {
    // Main variable
    bool running = true;

    // Start
    welcome();

    // Loop
    while (running) {
        // In Loop Variable
        int choosen_card [4];
        int input_type = 0;

        // Choosing input type
        while (input_type != 1 && input_type != 2) {
            cout << "Jenis input:\n1 - Input manual\n2 - Randomize input\n";
            cout << "Pilih metode input = ";
            cin >> input_type;
            if (input_type != 1 && input_type != 2) {
                cout << "Masukan metode input tidak tersedia!";
            }
        }
        
        // Inputing card to process
        if (input_type == 2) {
            for (int i = 0; i < 4; i++) {
                choosen_card[i] = randomizer();
            }
        } else if (input_type == 1) {
            for (int i = 0; i < 4; i++) {
                choosen_card[i] = userinput(i+1);
            }
        }

        // Displaying choosen card
        choosen_cards(choosen_card);

        // Start counting time
        long start_tick = clock();
        analyzingsolution();
        
        // Start solving
        string resulting24 = "";
        int solution_discovered = solver24(choosen_card, &resulting24);
        if (solution_discovered == 0) {
            cout << "Tidak ada solusi memenuhi\n";
        }

        // Stop counting time, save time
        long stop_tick = clock();
        double ellapsed_time = (double) (stop_tick - start_tick)/CLOCKS_PER_SEC;

        // Displaying counted solution and time
        solutionfounded(solution_discovered, ellapsed_time);

        // Asking for generating file output
        char saving;
        cout << "Apakah ingin menyimpan solusi sebagai file txt? (Y/N) ";
        cin >> saving;

        if (saving == 'Y') {
            string nama_file;
            cout << "Masukkan nama file: ";
            cin >> nama_file;
            fileoutput(solution_discovered, resulting24, nama_file);
        }

        // Asking for more solution
        char loop_again;
        cout << "Apakah ingin mencoba mencari solusi untuk kombinasi lain? (Y/N) ";
        cin >> loop_again;

        if (loop_again != 'Y') {
            running = false;
        }
    }

    thankyou();
}