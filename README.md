# TermProj

# Goal
the goal of this project is to make a dictiornay/spell checker that will take in words from a txt file, read them in and then also input them into a hashfunction


# Hashing
Firstly i created a table that was of size 26 for each letter of the alphabet
all words were hashed by first letter and then returned the mod 26 so that the words can be added by similar ascii values
the words were then inserted into into the table and from there i was able to get my case One started

# Case One

I declared a boolean value called exist that would help me see if there is a match or not,
I firstly pass a string from the main function to case one that is the word the user inputs.
I iterate throguh the table by firstly getting the hash value of the word inputted then searching the table for it
When i find the match i stop the iteration and if the word is found i set exist to be true, this indicates the word is found
i then return true and return the time it took to get that value which is started when the iteration starts
If exist is false then i go to case 2

# Case Two

I declare a boolean and an empty string  i do the same hashing as the previous case and iterate through the table at that hashfunction
Then based on lenght i compare the words and if there is a word that is the same lenght and first letter as the inputted word I ask the user if that is the word they meant
If the user says that is the word that they meant i return true and print out the correct word along with how long it took to get the word
If there is a match the program detects but that isnt the word the user wanted then i return false
If neither of the above are met meaning there isnt a word with the same length or first letter then i move onto case 3

# Case three
Here i just output false but only after the other two cases havent been met because that means that the word is not in the text file that is being read

# Suggestion function

in this function once case one or two returns true i get the hashfuntio of the word that is correct so in case it would be after the user confirms the misspelled word to be what i asked them to be and then i return only words that start with the same first two letters

# Main

in main i open the dictionary file and create a string called words and words will be the words i receive when i do the getline funciont to read ing
i push those words into a vector called text,sort it and then declare my hashtable size
i iterate through the vector and pass eah owrd into the insert function which will insert values based on hashvalue of first letter
I ask the user to input a word and send that word into case 1 and depending on the answer i send it to case 2 or 3
After the program does what it needs to i close the dictionary

