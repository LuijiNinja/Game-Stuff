#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    short fighter;
    int hp;
    int enemy_hp;
    int choice;
    int enemy;
    const int max_value = 3;
    const int min_value = 1;
    srand(time(nullptr));
    enemy = (rand() % (max_value - min_value + 1)) + min_value;

    int slash;
    int thrust;
    int roll_max = 6;
    int roll_min = 1;
    int crit = (rand() % (roll_max - roll_min + 1)) + roll_min;

    cout << "Welcome to the Colloseum!" << endl
         << "Place your bet!" << endl
         << "1. Sword and Board (15 hp)" << endl
         << "2. Net and Trident (10 hp)" << endl
         << "Your bet? :";
    cin >> fighter;
    if (fighter = 1)
    {
        hp = 15;
        slash = 5;
        int roll_max = 6;
        int roll_min = 1;

        cout << "A classic! You have:" << endl
             << "1. Slash (5 dmg)" << endl
             << "2. Thrust (4 dmg / CRIT 8 dmg)" << endl
             << "3. Shielded Defense (Half the Dmg taken)" << endl;
    }

    cout << "Let's Begin!" << endl;

    if (enemy = 1)
    {
        enemy_hp = 10;
        cout << "You face a fellow gladiator. He is equipped with a sword and shield.";

        while (enemy_hp > 0)
        {
            cout << endl
                 << "What action do you take?" << endl
                 << "Action: ";
            cin >> choice;
            if (choice == 1)
            {
                enemy_hp = enemy_hp - slash;
                cout << slash << " dmg" << endl
                     << "A mighty slash strikes your foe." << endl;
            }
            else if (choice == 2)
            {
                int crit = (rand() % (roll_max - roll_min + 1)) + roll_min;
                if (crit == 6)
                {
                    thrust = 8;
                }
                else if (crit < 6)
                {
                    thrust = 4;
                }

                cout << endl
                     << "A thrust forward!";
                if (crit == 6)
                {
                    enemy_hp = enemy_hp - thrust;
                    cout << endl
                         << "A vital has been struck!" << endl
                         << thrust << " DMG!" << endl;
                }
                else if (crit < 6)
                {
                    enemy_hp = enemy_hp - thrust;
                    cout << endl
                         << thrust
                         << " DMG!" << endl;
                }
            }
            else if (choice == 3)
            {
                cout << endl
                     << "A bold block." << endl;
            }

            cout << enemy_hp << " HP (Opponent)";

            int enemy_attack;
            int enemy_max = 2;
            int enemy_min = 1;
            int enemy_strike = 5;
            int enemy_stab = 2;
            enemy_attack = (rand() % (enemy_max - enemy_min + 1)) + enemy_min;
            if (enemy_attack == 1)
            {
                cout << endl
                     << "He strikes back!" << endl;
                if (choice == 3)
                    hp = hp - (enemy_strike / 2);
                else if (choice != 3)
                {
                    hp = hp - enemy_strike;
                }
            }

            else if (enemy_attack == 2)
            {
                cout << endl
                     << "He stabs!" << endl;
                if (choice == 3)
                {
                    hp = hp - (enemy_stab / 2);
                }
                else if (choice != 3)
                {
                    hp = hp - enemy_stab;
                }
            }

            cout << endl
                 << hp << " HP (Player)" << endl;
        }

        {
            cout << endl
                 << "You have come out a richer man!";
        }
    }
    return 0;
}