// Please modify this file as required

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// You can add more functions, structures, and vairables to this file.  
	// Helper functions must start with '_'.

//This is an example of a helper function.
	//clean function whenever malloc fails in shuffle function
void _error_clean()
{
	exit(EXIT_FAILURE);

}

#ifdef TEST_DIV
void divide(CardDeck orig_deck, CardDeck* upper_deck, CardDeck* lower_deck)
{
	//Dividing the desks into the way mentioned in the document - as lower and upper
	//Use a loop from index i to orig_deck.size - 1
		//starting from 1 -> size-1 copying into upper deck and lower decks

	int size = orig_deck.size;
	
	for(int i = 0; i < size - 1; i++)
	{
		strncpy((upper_deck[i].cards), orig_deck.cards, i + 1);
		upper_deck[i].size = i + 1;

		strncpy((lower_deck[i]).cards, orig_deck.cards + i + 1, orig_deck.size - i - 1);
		lower_deck[i].size = orig_deck.size - i - 1;
	}

			//strncpy((upper_deck[i]).cards, orig_deck.cards,i+1);
		//update size of upper deck
			//For example: upper_deck[i].size = i+1;
		//update size of lower deck:
			//For example: lower_deck[i].size = orig_deck.size -i -1;
}
#endif


#ifdef TEST_INTER

void helper(CardDeck new, char* upp, int usize, char* low, int lsize, int index, int repeat)
{
	if(usize == 0)
	{
		//this function fills with lower if upper deck hits 0 first
		for(int i = 0; i < lsize; i++)
		{
			new.cards[index] = low[i];
			index++;
		}
		repeat--;
		repeat_shuffle(new, repeat); //make sure to fill this out properly
		return;
	}
	if(lsize == 0)
	{
		//this function fills with upper if lower deck hits 0 first
		for(int i = 0; i < usize; i++)
		{
			new.cards[index] = upp[i];
			index++;	
		}
		repeat--;
		repeat_shuffle(new, repeat);
		return;
	}

	new.cards[index] = upp[0];
	helper(new, upp + 1, usize - 1, low, lsize, index + 1, repeat);
	new.cards[index] = low[0];
	helper(new, upp, usize, low + 1, lsize - 1, index + 1, repeat);

}
//repeat holds the number of shuffles yet to be performed.
//after the interleave operation has been completed, you will recursively call
	//repeat_shuffle(...) with a decremented value of repeat.
void interleave(CardDeck upper_deck, CardDeck lower_deck, int repeat)
{
    // Follow instructions in the README, to understand the working of the recursive function.
    // when the newly shuffled deck is complete:
    	//you will perform another k-1 rounds of shuffling with the new deck
    // Tip: There should be no uncertainty in this function.
        //If you think a random number generator is needed, you are on the wrong track.
    // Tip: To copy the elements of one array from one array to another (e.g., the array of cards in a CardDeck),
        //you could use memcpy(…).
        //The = operator will simply copy the address, not the elements themselves.

	CardDeck new;
	new.size = upper_deck.size + lower_deck.size;
	helper(new, upper_deck.cards, upper_deck.size, lower_deck.cards, lower_deck.size, 0, repeat);

}
#endif

#ifdef TEST_SHUF
//repeat holds the number of shuffles that are yet to be performed.
void shuffle(CardDeck orig_deck, int repeat)
{
    // declare a variable to hold the number of pairs
        // we can say that we have only size-1 possibility of pairs

	int pairs = orig_deck.size - 1;

    // if number of pairs == 0; return;
    
	if(pairs == 0)
	{
		fprintf(stderr, "The number of pairs must be greater than 0\n");
		return;
	}

	// instantiate pointers to hold both upper and lower decks (after division)
	   // For example: CardDeck * upper_deck = NULL;

	CardDeck * upp = NULL;
	CardDeck * low = NULL;

	// allocate memory based on number of pairs
	   //For example: upper_deck = malloc(numpairs*sizeof(CardDeck));

	upp = malloc(pairs * sizeof(CardDeck));
	low = malloc(pairs * sizeof(CardDeck));
	if(upp == NULL || low == NULL)
	{
		_error_clean();
	}

	// call divideDeck to fill upper_deck and lower_deck

	divide(orig_deck, upp, low);

	//run a loop through all the pairs
		// for each pair of upper and lower deck call interleave()
		// For example: interleave(upper_deck[i],lower_deck[i]);

	for(int iter = 0; iter < pairs; iter++)
	{
		interleave(upp[iter], low[iter], repeat);
	}

    // free memory allocated to upper and lower deck.

	free(upp);
	free(low);
}
#endif

#ifdef TEST_RSHUF
void repeat_shuffle(CardDeck orig_deck, int k)
{
	//orig_deck contains a deck of cards, and it's size.

	//int pairs = orig_deck.size - 1;

	//If (k ≤ 0), no shuffling, print the only possible outcome.
		//printDeck(orig_deck); and return
		//TIP: Print only the results obtained after k rounds of shuffling
	// call shuffle(orig_deck);
	
	if(k > 0)
	{
		//divide(orig_deck, upp, low);
		//for(int i = 0; i < pairs; i++)
		//{
			shuffle(orig_deck, k);
		//}
	}

	if(k <= 0)
	{
		printDeck(orig_deck);
		return;
	}

	// TIP: In interleave(…), when the newly shuffled deck is complete, 
		//you will perform another k-1 rounds of shuffling with the new deck.
}
#endif
