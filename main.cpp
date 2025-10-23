// main.cpp — ASCII Clicker Adventure
cout << "2) Buy auto income (+1 coin/tick) — Cost: " << 50 + 20LL * g.auto_income << "\n";
cout << "3) Level Up (increase level, reward 200 coins) — Cost: " << 100LL * g.level << "\n";
cout << "4) Back\n";
cout << "Choose (1-4): ";
string choice; getline(cin, choice);
if (choice == "1") {
long long cost = 10LL * g.clicks;
if (g.coins >= cost) {
g.coins -= cost;
g.clicks += 1;
cout << "Upgraded! Coins/click is now " << g.clicks << "\n";
} else cout << "Not enough coins.\n";
} else if (choice == "2") {
long long cost = 50 + 20LL * g.auto_income;
if (g.coins >= cost) {
g.coins -= cost;
g.auto_income += 1;
cout << "Auto income increased to " << g.auto_income << " per tick.\n";
} else cout << "Not enough coins.\n";
} else if (choice == "3") {
long long cost = 100LL * g.level;
if (g.coins >= cost) {
g.coins -= cost;
g.level += 1;
g.coins += 200; // bonus
cout << "Level up! Level " << g.level << ", bonus 200 coins.\n";
} else cout << "Not enough coins.\n";
} else break;
}
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);


Game g;
show_header();
cout << "A tiny demo clicker with a friendly narrative.\n";
cout << "Type 'help' for commands.\n";


string line;
while (true) {
show_status(g);
cout << "\n> ";
if (!getline(cin, line)) break;
if (line.empty()) continue;
if (line == "help") {
show_help();
} else if (line == "c" || line == "click") {
g.coins += g.clicks;
cout << "You click and gain " << g.clicks << " coins.\n";
} else if (line == "s" || line == "shop") {
shop(g);
} else if (line == "w" || line == "wait") {
g.coins += g.auto_income;
g.tick_count++;
cout << "A moment passes... you gain " << g.auto_income << " coins.\n";
// small event
if (g.tick_count % 10 == 0) {
cout << "A wandering merchant sees your fortune and smiles — small gift! (+5)\n";
g.coins += 5;
}
} else if (line == "save") {
save_game(g);
} else if (line == "load") {
load_game(g);
} else if (line == "q" || line == "quit") {
cout << "Quit and save? (y/n): ";
string x; getline(cin, x);
if (!x.empty() && (x[0] == 'y' || x[0] == 'Y')) save_game(g);
cout << "Goodbye adventurer!\n";
break;
} else {
cout << "Unknown command. Type 'help' to see commands.\n";
}
}
return 0;
}
