#include "wizards.hpp"
//#include"wizards.cpp"
#include<cstdlib>
using namespace std;

int main(int argc, char *argv[]){

	wizard *wizard_array;
	spellbook *spellbook_array;

	int num_wizard;
	int num_books;
	int num_spells;

	if(argc !=3)
		cout << "Not the correct number of input files" << endl;
	else{
		
		ifstream book;
		book.open(argv[1]);
		ifstream wiz;
		wiz.open(argv[2]);
		if(book.is_open() || wiz.is_open()){
			get_wizard(wizard_array, num_wizard, wiz);
			get_spellbook_data(spellbook_array, num_books, book);
			
			book.close();
			wiz.close();
			
			bool is_teacher = check_id(num_wizard, wizard_array);
	
			cout << is_teacher << endl;
	
		//	delete_info(&wizard_array, num_wizard, spellbook_array, num_books);	
		}	
		else{	
			cout << "Please enter valid file names" << endl;
			exit(0);
		}
		
	}

	return 0;
}

