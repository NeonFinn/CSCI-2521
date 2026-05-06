#include "CatsAndCougars.h"

/*
TODO: the constructor should call the reset function.
The reset function will set both the cats and cougars
class member variables to 0.
*/
CatsAndCougars::CatsAndCougars()
{
    reset();
}

/*
TODO: the getCats getter/accessor function only returns
the value of the cats class member variable.
*/
int CatsAndCougars::getCats()
{
	return cats;
}

/*
TODO: the getCougars getter/accessor function only returns
the value of the cougars class member variable.
*/
int CatsAndCougars::getCougars()
{
    return cougars;
}

/*
TODO: the count function will implement the logic to count
cats and cougars. Ensure the reset function is called first.
By callin the reset function, the count function ensures
the cats and cougars class member variables are reset to 0.
*/
void CatsAndCougars::count(string lword, string rword)
{
    reset();

    // for each letter in the guess
    for (int i = 0; i < lword.length(); i++)
    {
        // cat is correct letter in right spot
        if (lword[i] == rword[i])
        {
            cats++;
        }
        else
        {
            // cougar is correct letter but in wrong spot
            for (int j = 0; j < rword.length(); j++)
            {
                if (lword[i] == rword[j])
                {
                    cougars++;
                }
            }
        }
    }
}

/*
TODO: The reset function should only set the cats and cougars
class member variables to 0.
*/
void CatsAndCougars::reset()
{
    cats = 0;
    cougars = 0;
}