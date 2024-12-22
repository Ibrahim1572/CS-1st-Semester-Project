void menu_edit() {
    cout << "Enter restaurant number:" << endl;

    fstream res_name;
    string name;
    int counter = 1, res_num;

    // Display restaurant names
    res_name.open("res_name.txt");
    while (getline(res_name, name)) {
        cout << counter << "\t" << name << endl;
        counter++;
    }	 	
    res_name.close();

    cin >> res_num;
    if (res_num < 1 || res_num > 4) {
        cout << "Invalid restaurant number!" << endl;
        return; // Exit the function
    }

    // Open the menu file and read into memory
    fstream res_items("res_items.txt", ios::in);
    vector<string> file_content;
    string item, marker = "*";

    for (int i = 1; i < res_num; i++) {
        marker += "*";
    }

    // Read file content into a vector
    while (getline(res_items, item)) {
        file_content.push_back(item);
    }
    res_items.close();

    // Locate the marker in the file content
    int insert_position = -1;
    for (int i = 0; i < file_content.size(); i++) {
        if (file_content[i] == marker) {
            insert_position = i + 1;
            break;
        }
    }

    if (insert_position == -1) {
        cout << "Error: Restaurant marker not found!" << endl;
        return;
    }

    // Insert the new menu item at the correct position
    cout << "\nWhich dish do you want to enter?\n";
    string edit;
    cin.ignore();
    getline(cin, edit);

    file_content.insert(file_content.begin() + insert_position, edit);

    // Write the updated content back to the file
    ofstream menu_edit("res_items.txt", ios::out | ios::trunc);
    for (const auto& line : file_content) {
        menu_edit << line << endl;
    }
    menu_edit.close();

    cout << "\nDish added successfully\n";
}