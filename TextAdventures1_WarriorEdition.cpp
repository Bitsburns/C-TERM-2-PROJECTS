#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

//Key functions
void warrior_atk();
int randomDmg();
void displayStats(int playerHealth, double damageMult, string className);
void warrior_dodge();
int enemyatk1();
int enemyatk2();
int bossatk1();

//Warrior scene functions
void warrior_intro(int &health, double &mult, int &choices);
void warrior_scene1(int &health, double &mult, int &choices);
void warrior_scene2(int &health, double &mult, int &choices);
void warrior_end(int &health, double &mult, int &choices);

//Game Functions
int randomDmg() {
    return rand() % 40 + 5;
}
int enemyatk1(){
    return rand() % 20 + 5;
}
int enemyatk2(){
    return rand() % 25 + 1;
}
int bossatk1(){
    return rand() % 35 + 1;
}
void warrior_dodge(){
    int random = rand() % 3;

    string dodgelines[]{
        "Warrior braced himself and kept his footing.",
        "Warrior managed to block the enemy's attack with his sword.",
        "Warrior managed to barely avoid the enemy's attack.",
    };
    
    cout << dodgelines[random] << endl;
}

void displayStats(int playerHealth, double damageMult, string className){
    cout <<"\n=== " << className << " Stats ===" << endl;
    cout <<"Health remaining: " << playerHealth << endl;
    cout <<"Damage Multiplier: " << damageMult << endl;
    cout <<"==================================\n" << endl;
}

void warrior_atk(){
    int atk = randomDmg();

    string critFail[]{
        "Warrior trips on a branch and slightly misses the enemy!",
        "Warrior does a trick with his sword to look cool but whiffs his attack!",
        "Warrior stabs at the enemy but the enemy dodged!",
    };

    string normalHit[]{
        "Warrior slashes at the enemy and its armor!",
        "Warrior uses his sword handle to hit the enemy's head!",
        "Warrior swiftly punches the enemy in the face and sends it staggering back!",
    };
    string critHit[]{
        "Warrior charges at the enemy and lands a powerful hit!",
        "Warrior successfully slashed his sword at his enemy's chest dealing a massive gash!",
        "Warrior stabs his sword at the enemy and knocks it off balance, giving him an opening for another hit!",
    };

    cout << "Warrior readies his sword!" << endl;
    
    if(atk >= 5 && atk <= 11){
        int randomLine = rand() % 3;
        cout << critFail[randomLine] << endl;
        cout << "Critical Failure! Enemy Damage: " << atk << endl;
    }else if(atk >= 12 && atk <= 29){
        int randomLine = rand() % 3;
        cout << normalHit[randomLine] << endl;
        cout << "Success! Enemy Damage: " << atk << endl;
    }else if(atk >= 30 && atk <=40){
        int randomLine = rand() % 3;
        cout << critHit[randomLine] << endl;
        cout << "Critical Hit! Enemy Damage: " << atk << endl;
    }
}

/////// Warrior Scenes //////
void warrior_intro(int &health, double &mult, int &choices){

    cout << "Warrior was a proud soldier serving the Kingdom of Someworld. He has chosen to set out on a quest to gain riches to escape his title as a commoner. And earn a living as a wealthy merchant." << endl;
    getch();
    cout << "So leaving his home behind and waving to his mother goodbye, Warrior set out on a quest to leave for the harsh wilderness and mazelike forests." << endl;
    getch();
    cout << "With nothing but a sword on his hip and a few supplies to last him his journey, he left in search for the ruins of the ancient, mythical Kingdom of Hasgold..." << endl;
    getch();
    displayStats(health, mult, "Warrior");
}

void warrior_scene1(int &health, double &mult, int &choices){
    bool clear = false;

    while(!clear){
        int sceneStart = health;
        int wolf = 75;

        cout << "Warrior arrived found himself following a long winding path for miles without a soul in sight. Apart from a wild animal that strayed off the beaten path, Warrior was alone." <<endl;
        getch();
        cout << "Night came and Warrior decided to rest out on the side of the road for a bit and drink from his waterskin. He looked up and watched as the sun and the full moon glowed gently above him." <<endl;
        getch();
        cout << "Just then, a howl resounded close to him. Warrior stood up and braced himself for battle!" <<endl;
        getch();
        cout << "A scruffy werewolf pounced towards Warrior, its mouth open in a rabid, drooling grin!" << endl;


        while(wolf > 0 && health > 0){
            cout << "\n ---- Battle Status: ---- " << endl;
            cout << "Warrior Health: " << health << endl;
            cout << "Werewolf Health: " << wolf << endl;
            cout << "---------------------------\n" << endl;

            int wolfDmg = enemyatk1();
            
            if(wolfDmg >= 5 && wolfDmg <= 10){
                cout << "Werewolf snarls and attempts to bite Warrior." << endl;
            } else if(wolfDmg >= 11 && wolfDmg <= 14){
                cout << "Werewolf lets out an angry howl and slashes at Warrior!" << endl;
            } else if(wolfDmg >= 15 && wolfDmg <= 20){
                cout <<  "Werewolf lunges and catches Warrior off guard!" << endl;
            }

            cout << "[1] Attack! " << endl;
            cout << "[2] Brace! " << endl;

            bool validAction = false;
            while(!validAction) {
                int atk1;
                cin >> atk1;
                
                switch(atk1){
                    case 1: 
                {
                    warrior_atk();
                    int damage = randomDmg() * mult;
                    cout << "Warrior's passive, 'Formidable' activated! Damage increased to: " << damage << endl;
                    wolf -= damage;
                    validAction = true;
                    break;
                }
                case 2:{
                    warrior_dodge();
                    wolfDmg = wolfDmg / 2;
                    validAction = true;
                    break;
                }
                default:{
                    cout << "Invalid output. Please choose 1 or 2." << endl;
                }
                }
            }

            health -=wolfDmg;
            cout << "Warrior takes " << wolfDmg << " damage!" << endl;

        }
        if(health <= 0) {
            cout << "Warrior screams as the werewolf pins him down and tears his neck out with its teeth." << endl;
            getch();
            cout << "Game over." << endl;
            getch();
            cout << "Try again?\n[1] Yes\n[2] No" << endl;
            int trygin;
            cin >> trygin;
            if(trygin == 1) {
                health = sceneStart;
            } else {
                clear = true;
            }
        } else {
            cout << "The werewolf lets out a yelp as it fell onto the floor with a heavy thudd. It looks up at Warrior in fear, its eyes wide with newfound terror." << endl;
            getch();
            
            bool validChoice = false;
            while(!validChoice) {
                cout << "[1] Kill it\n[2] Spare it\n[3] Rob it" << endl;
                int ch;
                cin >> ch;
                
                if(ch == 1){
                    choices--;
                    cout << "The werewolf lets out a terrified yelp as Warrior stabs his sword into its neck. It dies with a choke, its body convulsing." << endl;
                    getch();
                    cout << "Warrior noticed a glass of potion underneath the creature but was deemed unusuable due to the glass cracking and its contents spilling on the dirt." << endl;
                    getch();
                    cout << "Oh well, time to move on. Press any key to continue..." << endl;
                    validChoice = true;
                }else if(ch == 2){
                    choices ++;
                    cout << "Warrior sheathed his sword and watched as the werewolf runs away. Then he realized the werewolf dropped a health potion onto the grass as it fled to the woods." << endl;
                    health += 15;
                    getch();
                    cout << "Warrior's health increased by 15! Health is now " << health << "!" << endl;
                    cout << "Press any key to continue..." << endl;
                    validChoice = true;
                }else if(ch == 3){
                    cout << "Warrior pointed his sword at the werewolf and demanded it give him all its valuables. The werewolf attempts to give him everything it has but it only had a health potion to spare." << endl;
                    getch();
                    health +=10;
                    cout << "The werewolf flees after Warrior robs it of its potion. Warrior's health increased to 10! Health is now " << health << "!" << endl;
                    cout << "Press any key to continue..." << endl;
                    validChoice = true;
                }else{
                    cout << "Invalid input! Please choose 1, 2, or 3." << endl;
                }
            }
            cout << "Warrior sets off into the road onto his next adventure to the Kingdom of Hasgold..." << endl;
            getch();
            cout << "Area Clear! Warrior gained back 30 health!" << endl;
            health += 30;
            displayStats(health, mult, "Warrior");
            getch();
            clear = true;
        }

    }
}

void warrior_scene2(int &health, double &mult, int &choices){
    bool clear = false;
    while(!clear){
        int sceneStart = health;
        int chimera = 100;

        cout << "For some reason, Warrior ended up somewhere in the middle of an abandoned village. Buildings were destroyed and houses were burned to near ash. Not to mention the sickening scent of a poison lingered in the air." << endl;
        getch();
        cout << "Warrior is driven by a need to slay whoever or whatever did this. So finding clues on any remaining survivors, Warrior found himself following a trail and eventually climbing down a craggy valley where a few remaining survivors had settled into old, ragged tents." << endl;
        getch();
        cout << "Warrior could see many have been injured. Only two soldiers, an elderly veteran and a young recruit had survived with their skins blanched in necrotic poison, their armors singed by what looked like remnants of flames and ashes." << endl;
        getch();
        cout << "Warrior spoke to a few men, women and children settling into the campsite and asked for who or whatever caused this disaster. Sure enough it was a chimera, a hybrid between a lion, a serpent and a goat. These abominations spit out poison from the serpent and fire through the lion's maw." << endl;
        getch(); 
        cout << "Warrior followed the elderly veteran's direction on where they saw the chimera flee. And so went Warrior, into the lion's den." << endl;
        cout << "Warrior could smell the stench of the creature as it ate through piles of what looked like rotting meat. As it noticed Warrior's presence, it lets out an angry roar." << endl;

        while(chimera > 0 && health > 0){
            cout << "\n ---- Battle Status: ---- " << endl;
            cout << "Warrior Health: " << health << endl;
            cout << "Chimera Health: " << chimera << endl;
            cout << "---------------------------\n" << endl;
            
            int chimeraDmg = enemyatk2();
            
            if(chimeraDmg >= 1 && chimeraDmg <= 4){
                health += 5;
                cout << "Chimera is exhausted! Warrior takes advantage of the break and patches up his wounds!" << endl;
                chimeraDmg = 0;
            }else if(chimeraDmg >= 5 && chimeraDmg <= 10){
                cout << "Chimera slashes its claws at Warrior!" << endl;
            } else if(chimeraDmg >= 11 && chimeraDmg <= 14){
                cout << "Chimera lets out an angry snarl as the snake on its tail spits out poison!" << endl;
            } else if(chimeraDmg >= 15 && chimeraDmg <= 25){
                cout <<  "Chimera lets out a defeaning roar as it breathes fire towards Warrior!" << endl;
            }

            cout << "[1] Attack! " << endl;
            cout << "[2] Brace! " << endl;

            bool validAction = false;
            while(!validAction) {
                int atk1;
                cin >> atk1;
                
                switch(atk1){
                    case 1: 
                {
                    warrior_atk();
                    int damage = randomDmg() * mult;
                    cout << "Warrior's passive, 'Formidable' activated! Damage increased to: " << damage << endl;
                    chimera -= damage;
                    validAction = true;
                    break;
                }
                case 2:{
                    warrior_dodge();
                    chimeraDmg = chimeraDmg / 2;
                    validAction = true;
                    break;
                }
                default:{
                    cout << "Invalid output. Please choose 1 or 2." << endl;
                }
                }
            }
            health -=chimeraDmg;
            cout << "Warrior takes " << chimeraDmg << " damage!" << endl;
        }
        if(health <= 0) {
            cout << "Warrior screams as the chimera bites down on his stomach and pins him down the ground. The last thing he sees is the chimera's maw as it eats him alive." << endl;
            getch();
            cout << "Game over." << endl;
            getch();
            cout << "Try again?\n[1] Yes\n[2] No" << endl;
            int trygin;
            cin >> trygin;
            if(trygin == 1) {
                health = sceneStart;
            } else {
                clear = true;
            }
        } else {
            cout << "The chimera lets out a growl as it falls on the ground. It stares at Warrior in anger." << endl;
            getch();
            
            bool validChoice = false;
            while(!validChoice) {
                cout << "[1] Kill it\n[2] Spare it\n[3] Rob it" << endl;
                int ch;
                cin >> ch;
                
                if(ch == 1){
                    choices++;
                    health += 20;
                    cout << "Warrior stabs his sword straight into the beast's chest." << endl;
                    getch();
                    cout << "As if being rewarded by his heroic deed, Warrior felt a burst of light and his wounds healed in an instant." << endl;
                    getch();
                    cout << "Warrior's health increased by 20!" << endl;
                    validChoice = true;
                }else if(ch == 2){
                    choices --;
                    health -= 5;
                    cout << "Warrior spared the chimera. But the chimera was already dying. So with its remaining strength, the chimera breathed a burst of hot flames straight into Warrior. Warrior barely managed to dodge and was injured in the process." << endl;
                    getch();
                    cout << "Warrior was injured by 5 points!" << endl;
                    getch();
                    validChoice = true;
                }else if(ch == 3){
                    cout << "Warrior cannot rob the chimera. With its remaining strength, the chimera burns Warrior with its breath before taking its last breath." << endl;
                    getch();
                    health = 0;
                    cout << "Warrior died. Game over." << endl;
                    cout << "Try again?\n[1] Yes\n[2]No" << endl;
                    int dead;
                    cin >> dead;
                    if(dead == 1){
                        health = sceneStart;
                    }else if(dead == 2){
                        cout << "Ending program...";
                        clear = true;
                    }
                    validChoice = true;
                }else{
                    cout << "Invalid input! Please choose 1 or 2." << endl;
                }
            }
            cout << "Warrior collected a handful of the dead beast's hair. Noticing a strange looking symbol etched on the beast's back, Warrior etched it on his journal and walked back to the campsite with curious thoughts." << endl;
            getch();
            cout << "Walking back to the campsite Warrior showed the survivors the beast's hair as proof that he had killed it. After asking around the town about what the symbol meant Warrior finally found a lead. A symbol of the Kingdom of Hasgold, and ancient ruins just southwest the ruined town. He was closer than ever to his goal." << endl;
            getch();
            cout << "And though the fallen of the ruined village can never be brought back, the remaining townspeople showed their gratitude towards Warrior by pooling their money together and paying him for his deeds. And so, with a satchel full of coins off went Warrior to his next adventure." << endl;
            getch();
            displayStats(health, mult, "Warrior");
            getch();
            cout << "Area Clear! Warrior gained back 30 health!" << endl;
            health += 30;
            clear = true;
        }
    }
}

void warrior_end(int &health, double &mult, int &choices){
    bool clear = false;
    while(!clear){
        int sceneStart = health;
        int king = 170;

        cout << "The kingdom was in a much better state than Warrior though. Though the dilapidated gate was overgrown with weeds and vines, the inside was still somewhat intact." << endl;
        getch();
        cout << "Centuries of intricately carved stonework greeted him and as he delved deep in the eerily quiet town, he finally reached the castle." << endl;
        getch();
        cout << "Warrior was sure he'd find treasures inside. He could already see the vault the old ruler had hidden somewhere. Sure enough the marbled floors and rusted silver chandeliers looked promising." << endl;
        getch();
        cout << "What awaited at the throne room wasn't what Warrior expected. A golden statue of a king, sat atop a golden throne and an entirely golden room. And right beside it were chests upon chests of gold, gems and adventurers that had turned to gold. He'd hit the jackpot but the king wasn't about to let him out alive in his eternal greed." << endl;
        getch(); 
        cout << "Warrior watched as the golden statue rose from the throne and pulled a golden sword adorned with diamonds in its handle. Sure enough the symbol on the chimera's body was also drawn into the handle. Warrior braced himself for a fight." << endl;
        getch();
        cout << "Get ready for boss battle!!" << endl;
        cout << "============================" << endl;
        getch();

        while(king > 0 && health > 0){
            cout << "\n ---- Battle Status: ---- " << endl;
            cout << "Warrior Health: " << health << endl;
            cout << "King GoldDude the III Health: " << king << endl;
            cout << "---------------------------\n" << endl;
            getch();            
            int kingDmg = bossatk1();
            
            if(kingDmg >= 1 && kingDmg <= 4){
                cout << "The king's lifted his sword and sent in a massive arched slash towards warrior. It sent sparks through the air as it hit Warrior's armor." << endl;
            }else if(kingDmg >= 5 && kingDmg <= 19){
                health += 14;
                cout << "The King lost lost his footing and was temporarily stunned! Warrior uses this opportunity to heal himself." << endl;
                kingDmg = 0;
            } else if(kingDmg >= 20 && kingDmg <= 24){
                cout << "The King swings his sword at Warrior and sends him staggering back! The king swiftly swung again as Warrior lost his footing and hits his armor with the blade." << endl;
            } else if(kingDmg >= 25 && kingDmg <= 35){
                cout <<  "The King stabs his sharp blade at Warrior and sliced cleanly through warrior's skin! The king swings again and Warrior barely managed to avoid having his neck cut open." << endl;
            }

            cout << "[1] Attack! " << endl;
            cout << "[2] Brace! " << endl;

            bool validAction = false;
            while(!validAction) {
                int atk1;
                cin >> atk1;
                
                switch(atk1){
                    case 1: 
                {
                    warrior_atk();
                    int damage = randomDmg() * mult;
                    cout << "Warrior's passive, 'Formidable' activated! Damage increased to: " << damage << endl;
                    int dmd = damage + 10;
                    getch();
                    cout << "Warrior is Determined. His attack increases by 10! Damage increased to " << dmd << "!" << endl;
                    king -= dmd;
                    validAction = true;
                    break;
                }
                case 2:{
                    warrior_dodge();
                    kingDmg = kingDmg / 2;
                    validAction = true;
                    break;
                }
                default:{
                    cout << "Invalid output. Please choose 1 or 2." << endl;
                }
                }
            }
            health -=kingDmg;
            cout << "Warrior takes " << kingDmg << " damage!" << endl;
        }
        if(health <= 0) {
            cout << "Warrior lets out a wince as he felt the blade of King GoldDude pierce his heart. The last thing he feels is the coldness of his body as he was slowly turned into gold." << endl;
            getch();
            cout << "Game over." << endl;
            getch();
            cout << "Try again?\n[1] Yes\n[2] No" << endl;
            int trygin;
            cin >> trygin;
            if(trygin == 1) {
                health = sceneStart;
            } else {
                clear = true;
            }
        } else {
            cout << "Warrior's attacks had chipped away at King GoldDude's golden body. After days of grueling battle, King GoldDude's body had run down into a cracked statue. With one swift kick, the king's golden body fell apart into chunks of uneven gold." << endl;
            getch();
            if(choices == 2){
                cout << "Warrior has won. A cold, empty silence settled around him as he drank from his waterskin. Days of battling had tired him out but he won. His legacy as the chimera slayer and King GoldDude's killer would forever live on. Though the gold he'd earned through it all was what truly made it all worth it." << endl;
                getch();
                cout << "As Warrior collected as much as he could fill in his bag, a particular artifact caught his eye. A peculiar red, glass chalice with the symbol of King GoldDude's handle and the one etched into the chimera's skin... It called to him, to take it..." << endl;
                getch();
                cout << "Warrior wasn't tempted. He knew the artifact was evil. And so Warrior destroyed it by breaking it on the golden floor before starting his journey back home.\n" << endl;
                getch();
                cout << "\nHonorable Ending.";

            }else if(choices == -2){
                cout << "Warrior has won. A cold, empty silence settled around him as he drank from his waterskin. Days of battling had tired him out but he won. His legacy as the chimera slayer and King GoldDude's killer would forever live on. Though the gold he'd earned through it all was what truly made it all worth it." << endl;
                getch();
                cout << "But the gold he had wasn't nearly enough. He wanted more. Money. Wealth and power. An evil artifact, a red glass chalice tempted him promising power to those who touched it." << endl;
                getch();
                cout << "Warrior took it in his hands and before he knew it he was filled raw power. Strength beyond his wildest dreams. But like King GoldDude III, he was now trapped. Doomed to hoard all the treasures he earned and doomed to kill the next unlucky adventurer who entered the throne room... for all of eternity until his curse somehow breaks.\n" << endl;
                getch();
                cout << "\nCursed by the Chalice Ending.";
            }else if(choices == 1 || choices == -1 || choices == 0){
                cout << "Warrior has won. A cold, empty silence settled around him as he drank from his waterskin. Days of battling had tired him out but he won. His legacy as the chimera slayer and King GoldDude's killer would forever live on. Though the gold he'd earned through it all was what truly made it all worth it." << endl;
                getch();
                cout << "Ignoring the creepy chalice on one of the chests, Warrior hoarded as much gold as he could before setting off, back home.\n" << endl;
                getch();
                cout << "\nGreedy Ending";
            }

            displayStats(health, mult, "Warrior");
            getch();
            clear = true;
        }
    }
}

int main(){
    srand(time(0));
    char choice1;
    int playerhealth = 0;
    double damageMult = 0;
    int choice = 0;

    cout << "Welcome to Text Adventures 1: Warrior edition!\nPress any key to start the game.." << endl;
    getch();
    cout << "Before we start, please state your difficulty preference." << endl;
    cout << "Choose:\n[1] Easy (Higher Health and higher multiplier damage)\n[2] Normal (Default)\n[3] Hard (Default health but no multiplier damage. This mode is pure RNG)" << endl;
    cin >> choice1;

    switch(choice1){
        case '1':
        playerhealth = 60;
        damageMult = 1.8;
        cout << "You chose Easy!" << endl;
        getch();
        displayStats(playerhealth, damageMult, "Warrior");
        getch();
        cout << "The rules of the game is simple. You deal a random damage from 1 - 15 to the enemies. You also have different choices that affect the ending. You lose if your health drops to zero or negative. If you die, you can restart from the scene you were last killed in." << endl;
        getch();
        cout << "That's about it. Thank you for playing! Have fun and enjoy the game!\nPress any key to continue..." << endl;
        cout << setfill('\n') << setw(3) << " " << endl;
        getch();
        warrior_intro(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_scene1(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_scene2(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_end(playerhealth, damageMult, choice);
        return 0;
        case '2':
        playerhealth = 40;
        damageMult = 1.4;
        cout << "You chose Normal!" << endl;
        getch();
        displayStats(playerhealth, damageMult, "Warrior");
        getch();
        cout << "The rules of the game is simple. You deal a random damage from 1 - 15 to the enemies. You also have different choices that affect the ending. You lose if your health drops to zero or negative. If you die, you can restart from the scene you were last killed in." << endl;
        getch();
        cout << "That's about it. Thank you for playing! Have fun and enjoy the game!\nPress any key to continue..." << endl;
        cout << setfill('\n') << setw(3) << " " << endl;
        getch();
        warrior_intro(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_scene1(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_scene2(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_end(playerhealth, damageMult, choice);
        return 0;
        case '3':
        playerhealth = 40;
        damageMult = 1.0;
        cout << "You chose Hard!" << endl;;
        getch();
        displayStats(playerhealth, damageMult, "Warrior");
        getch();
        cout << "The rules of the game is simple. You deal a random damage from 1 - 15 to the enemies. You also have different choices that affect the ending. You lose if your health drops to zero or negative. If you die, you can restart from the scene you were last killed in." << endl;
        getch();
        cout << "That's about it. Thank you for playing! Have fun and enjoy the game!\nPress any key to continue..." << endl;
        cout << setfill('\n') << setw(3) << " " << endl;
        getch();
        warrior_intro(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_scene1(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_scene2(playerhealth, damageMult, choice);
        cout << setfill('\n') << setw(3) << " " << endl;
        warrior_end(playerhealth, damageMult, choice);
        return 0;
        default: 
        cout << "Invalid option. Please restart the program and try again.";
        return 0;
    }
    return 0;
}
