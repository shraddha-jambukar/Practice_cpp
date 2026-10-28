#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* prev;
    Song* next;
};

Song* head = nullptr;
Song* current = nullptr;

void addSong(string name) {
    Song* p = new Song{name, nullptr, nullptr};

    if (head == nullptr) {
        head = current = p;
    } else {
        Song* q = head;
        while (q->next != nullptr)
            q = q->next;

        q->next = p;
        p->prev = q;
    }

    cout << "Song added: " << name << endl;
}

void displayForward() {
    Song* p = head;

    if (p == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nPlaylist (Forward): ";
    while (p != nullptr) {
        cout << p->name << " <-> ";
        p = p->next;
    }
    cout << "NULL\n";
}

void displayReverse() {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    Song* p = head;
    while (p->next != nullptr)
        p = p->next;

    cout << "\nPlaylist (Reverse): ";
    while (p != nullptr) {
        cout << p->name << " <-> ";
        p = p->prev;
    }
    cout << "NULL\n";
}

void deleteSong(string name) {
    Song* p = head;

    while (p != nullptr && p->name != name)
        p = p->next;

    if (p == nullptr) {
        cout << "Song not found.\n";
        return;
    }

    if (p->prev != nullptr)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != nullptr)
        p->next->prev = p->prev;

    if (current == p)
        current = (p->next != nullptr) ? p->next : p->prev;

    delete p;
    cout << "Song deleted successfully.\n";
}

void playCurrent() {
    if (current == nullptr)
        cout << "Playlist is empty.\n";
    else
        cout << "Now playing: " << current->name << endl;
}

void playNext() {
    if (current == nullptr)
        cout << "Playlist is empty.\n";
    else if (current->next == nullptr)
        cout << "This is the last song.\n";
    else {
        current = current->next;
        playCurrent();
    }
}

void playPrevious() {
    if (current == nullptr)
        cout << "Playlist is empty.\n";
    else if (current->prev == nullptr)
        cout << "This is the first song.\n";
    else {
        current = current->prev;
        playCurrent();
    }
}

void playAll() {
    Song* p = head;

    if (p == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nPlaying all songs:\n";
    while (p != nullptr) {
        cout << "Now playing: " << p->name << endl;
        p = p->next;
    }
}

void repeatAll() {
    if (head == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    cout << "\nRepeat All (one complete cycle):\n";
    playAll();
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All Songs (one cycle)\n";
        cout << "10. Show Current Song\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, name);
                addSong(name);
                break;
            case 2:
                cout << "Enter song name to delete: ";
                getline(cin, name);
                deleteSong(name);
                break;
            case 3:
                displayForward();
                break;
            case 4:
                displayReverse();
                break;
            case 5:
            case 10:
                playCurrent();
                break;
            case 6:
                playNext();
                break;
            case 7:
                playPrevious();
                break;
            case 8:
                playAll();
                break;
            case 9:
                repeatAll();
                break;
            case 0:
                cout << "Exiting playlist manager.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

