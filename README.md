# TermProj

# Goal
the goal of this project is to make a dictionary/spell checker that will take in words from a txt file, read them in and then also input them into a hashfunction


# Hashing
Firstly i created a table that was of size 26 for each letter of the alphabet
all words were hashed by first letter and then returned the mod 26 so that the words can be added by similar ascii values
the words were then inserted into into the table and from there i was able to get my case One started

# Case One
  
  CASE ONE IS INTENDED FOR IF THE USER INPUTS A WORD CORRECTLY AND IT EXISTS WITHIN THE READ IN FILE
Using a declared a boolean value called exist that would help me see if there is a match or not,
firstly pass a string from the main function to case one that is the word the user inputs.
iterate through the table by firstly getting the hash value of the word inputted then searching the table for it
When a match is found the program stops the iteration and if the word is found it sets exist to be true, this indicates the word is found
then it will return true and return the time it took to get that value which is started when the iteration starts
If exist is false then case two is ran

# Case Two
  CASE TWO IS INTENDED FOR IF THE USER INPUTS A WORD INCORRECTLY BUT IT STILL EXISTS WITHIN THE READ IN FILE, THE PROGRAM WILL BEGIN SPELL CHECKING TO FIND                                                           DESIRED WORD
using another boolean value and an empty string the same hashing is done as the previous case and again iterated through the table at that hashfunction
Then based on length if a match is found based on length and first letter as the inputted word, program will  ask the user if that is the word they meant
If the user says that is the word that they meant the program will return true and print out the correct word along with how long it took to get the word
If there is a match the program detects but that isnt the word the user wanted then the program returns false
If neither of the above are met meaning there isnt a word with the same length or first letter then case three is executed

# Case three
  CASE THREE IS INTENDED FOR IF THE USER INPUTS A WORD INCORRECTLY AND IT DOES NOT EXISTS WITHIN THE READ IN FILE
Here the program will just output false but only after the other two cases havent been met because that means that the word is not in the text file that is being read

# Suggestion function
 A word is suggested to the user once either case one or two is met. When the program is able to return the correct word it will iterate through again in that same hashfunction spot and return letters with the same first two letters of the correct word. For example if the word is "plant" and it is found and the user confirms this is the word they meant it will return "play, player, planted".

# Main

in main i open the dictionary file and create a string called words and words will be the words i receive when i do the getline funciont to read ing
i push those words into a vector called text,sort it and then declare my hashtable size
i iterate through the vector and pass eah owrd into the insert function which will insert values based on hashvalue of first letter
I ask the user to input a word and send that word into case 1 and depending on the answer i send it to case 2 or 3
After the program does what it needs to i close the dictionary

