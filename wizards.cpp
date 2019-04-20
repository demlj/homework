#include "wizards.hpp"
using namespace std;

struct wizard{
	string name;
	int id;
	string password;
	string position_title;
	float beard_length;
};

struct spellbook{
	string title;
	string author;
	int num_pages;
	int edition;
	int num_spells;
	float avg_success_rate;
	struct spell *s;
};

struct spell{
	string name;
	float success_rate;
	string effect;
	int spell_sort;
};

spellbook * create_spellbooks(int num_books){
	spellbook* spellbook_array = new spellbook[num_books];
	return spellbook_array;
}

void get_spellbook_data(spellbook * spellbook_array, int num_books, ifstream &file_in){
	
	file_in >> num_books;
	spellbook_array = create_spellbooks(num_books);
	
	for(int i=0; i < num_books; i++){
		float sum = 0;
		file_in >> spellbook_array[i].title;
		file_in >> spellbook_array[i].author;
		file_in >> spellbook_array[i].num_pages;	
		file_in >> spellbook_array[i].edition;
		file_in >> spellbook_array[i].num_spells;
			
		spellbook_array[i].s = create_spells(spellbook_array[i].num_spells);
		get_spell_data(spellbook_array[i].s, spellbook_array[i].num_spells, file_in);
		
		for(int j = 0; j < spellbook_array[i].num_spells; j++){
			sum += spellbook_array[i].s[j].success_rate;
		}
		spellbook_array[i].avg_success_rate = sum / (float)spellbook_array[i].num_spells;
	}
}

void get_spell_data(spell *spells, int num_spells, ifstream &file_in){
	for(int k = 0; k < num_spells; k++){
	    	file_in >> spells[k].name;
		file_in >> spells[k].success_rate;
		file_in >> spells[k].effect;
	}
}

spell * create_spells(int num_spells){
	spell * spell_array = new spell[num_spells];
	return spell_array;
}

wizard * create_wizard(int num_wizard){
	wizard* wizard_array = new wizard[num_wizard];
	return wizard_array;
}

void get_wizard(wizard* wizard_array, int num_wizard, ifstream &wizard_in){
	wizard_in >> num_wizard;
	create_wizard(num_wizard);

	for(int i = 0; i < num_wizard; i++){
		wizard_in >> wizard_array[i].name;
		wizard_in >> wizard_array[i].id;
		wizard_in >> wizard_array[i].password;
		wizard_in >> wizard_array[i].position_title;
		wizard_in >> wizard_array[i].beard_length;
	}
}

bool check_id(int num_wizard, wizard *wizard_array){
	string str1 = "Teacher";
	string str2 = "Headmaster";
	int user_id;
	string pass;

	cout << "Please enter in your ID:" << endl;
	cin >> user_id;
	cout << "Please enter in your password:" << endl;
	cin >> pass;

	for(int i = 0; i < num_wizard; i++){
		if(user_id == (wizard_array[i].id)){
			if(pass.compare(wizard_array[i].password) == 0){
				if(str1.compare(wizard_array[i].position_title) == 0)
					return true;
				else if(str2.compare(wizard_array[i].position_title) == 0)
					return true;
				else 
					return false;
			}
			else if(i == num_wizard-1){
				cout << "Error, please re-enter your information" << endl;
				check_id(num_wizard, wizard_array);
			}
		}
	}
}



void delete_info(wizard *wizard_array, int num_wizard, spellbook *spellbook_array, int num_books){
        delete []wizard_array;
	wizard_array = NULL;

	for(int i = 0; i < num_books; i++){
		delete []spellbook_array[i].s;
		spellbook_array[i].s = NULL;
	}
	delete []spellbook_array;
	spellbook_array = NULL;
}

void swap(spellbook book1, spellbook book2){
	spellbook temp;
	temp = book1;
	book1 = book2;
	book2 = temp;
}

void sort_by_rate(spellbook *spellbook_array, int num_books){
	for(int i = 0; i < num_books; i++){
		for(int j = 0; j < num_books - i - 1; j++){

			if( spellbook_array[j].avg_success_rate > spellbook_array[j+1].avg_success_rate )
			       swap(spellbook_array[j], spellbook_array[j+1]);	
		}
	}
}

void sort_by_pages(spellbook *spellbook_array, int num_books){
	for(int i = 0; i < num_books; i++){
    		for(int j = 0; j < num_books - i - 1; j++){

	        	if( spellbook_array[j].num_pages > spellbook_array[j+1].num_pages)
	                       	swap(spellbook_array[j], spellbook_array[j+1]);
		}
	}
}	
void sort_by_type(spellbook *spellbook_array, int num_books){
			
	for(int i = 0; i < num_books; i++){
		for(int j = 0; j < spellbook_array[i].num_spells; j++){

			if(strcmp(spellbook_array[i].s[j].effect.c_str(), "bubble") == 0)
				spellbook_array[i].s[j].spell_sort = 1;

			if(strcmp(spellbook_array[i].s[j].effect.c_str(), "memory_loss") == 0)
				spellbook_array[i].s[j].spell_sort = 2;

			if(strcmp(spellbook_array[i].s[j].effect.c_str(), "fire") == 0)
				spellbook_array[i].s[j].spell_sort = 3;

			if(strcmp(spellbook_array[i].s[j].effect.c_str(), "poison") == 0)
				spellbook_array[i].s[j].spell_sort = 4;

			if(strcmp(spellbook_array[i].s[j].effect.c_str(), "death") == 0)
				spellbook_array[i].s[j].spell_sort = 5;

		}
	}
}	
