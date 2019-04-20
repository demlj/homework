#include<iostream>
#include<string>
#include<fstream>
#include<string.h>

#ifndef WIZARDS_H
#define WIZARDS_H


using namespace std;

struct wizard;
struct spellbook;
struct spell;

/*********************************************************************
 * ** Function: Create_wizard
 * ** Description:Creates the wizard struct array based on number of wizards
 * ** Parameters:number of wizards
 * ** Pre-Conditions: run after get_wizard
 * ** Post-Conditions:
 * *********************************************************************/
wizard * create_wizard(int num_wizard);

/*********************************************************************
 * ** Function: create_spellbooks
 * ** Description: Creates the array of structs for the spellbooks 
 * ** Parameters: number of spellbooks read from the file
 * ** Pre-Conditions: run after the get_wizard function
 * ** Post-Conditions:
 * *********************************************************************/
spellbook * create_spellbooks(int);

/*********************************************************************
   ** Function: get_spellbook_data
   ** Description: Reads in the spellbook data from the file and calls create spellbook
   ** Parameters:pointer to spellbook struct array, integer for num_spellbook, and ifstream from input file
   ** Pre-Conditions:User must be logged in already and provide correct files for this function to operate
   ** Post-Conditions: calls the create and get functions for spells which fills in the spells structs
   *********************************************************************/

void get_spellbook_data(spellbook *, int, ifstream &);

/*********************************************************************
 * ** Function: Create_spell
 * ** Description: allocates memory for array of size determined by number of spells per book
 * ** Parameters: number of spells to be found in each book
 * ** Pre-Conditions: Runs after the spellbook struct has been created; exists in the spellbook struct
 * ** Post-Conditions: 
 * *********************************************************************/

spell * create_spells(int);

/*********************************************************************
 * ** Function: get_spell_data
 * ** Description: gets the spell information from the spellbook.txt file
 * ** Parameters: called after the get_spellbook function which fills in the required number of spells per book
 * ** Pre-Conditions: requires the spells struct, int for number of spells, and the input file stream continued from above
 * ** Post-Conditions: 
 * *********************************************************************/

void get_spell_data(spell *spells, int, ifstream&);

/*********************************************************************
 * ** Function: delete_info
 * ** Description: deletes the info within the spellbook and wizard structs
 * ** Parameters: the struct arrays are required as well as the number of books and wizards
 * ** Pre-Conditions:
 * ** Post-Conditions: End of program
 * *********************************************************************/

void delete_info(wizard *wizard_array, int, spellbook *spellbook_array, int);

/*********************************************************************
 * ** Function: get_wizard
 * ** Description: reads in info from the wizard.txt file and reads the information into the wizard struct array
 * ** Parameters: wizard array, num of wizards, and the continued ifstream opened at the beginning of main
 * ** Pre-Conditions: Wizard array must have allocated memory
 * ** Post-Conditions:
 * *********************************************************************/

void get_wizard(wizard *, int, ifstream &);

/*********************************************************************
 * ** Function: check_id
 * ** Description: function searches line by line until an equivalent id is found. When found, the program compares the users password to the one on file. After that, if the student is a teacher, it returns true, else it returns false.
 * ** Parameters: int num_wizards, and the wizard array
 * ** Pre-Conditions: files input on command line must be valid
 * ** Post-Conditions:
 * *********************************************************************/

bool check_id(int, wizard*);

void sort_by_type(spellbook*, int num_books);

void sort_by_rate(spellbook*, int);

void sort_by_pages(spellbook*, int);

#endif	


