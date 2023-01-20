#include <iostream>
#include <unordered_map>

/**
 
Write a function
bool fancy_shuffle(char* s);

which rearranges characters in the string given as input, in such a way that no same character occurs twice in a row (that is, next to each other).
If such rearrangement is not possible, the function should return false.
 */ 

bool fancyShuffle(char* s)
{
    auto charCount = std::unordered_map<char, int>();
    int i;

    // build hash map of character count
    for (i = 0; s[i] != '\0'; i++)
    {
        auto currentCountIt = charCount.find(s[i]);
        if (currentCountIt == std::end(charCount))
        {
            charCount.insert(std::make_pair(s[i], 1));
        }
        else
        {
            currentCountIt->second++;
        }
    }

    int len = i;
    if (len <= 1)
    {
        return true;
    }
    
    // Find the largest group
    auto maxPairIt = std::begin(charCount);
    for (auto it = std::begin(charCount); it != std::end(charCount); ++it)
    {
        if (it->second > maxPairIt->second)
        {
            maxPairIt = it;
        }
    }

    // Check if shuffling is possible
    if (maxPairIt->second > (len+1)/2)
    {
        return false;
    }

    auto current = maxPairIt;
    i = 0;

    std::cout << "s original: " << s << "\n";
    do 
    {
        std::cout << "i: " << i << "; doing char: " << current->first << " -- " << 
            current->second << "\n";
        // Start populating on alternating positions
        for (int j = 0; j < current->second; j++)
        {
            s[i] = current->first;
            i += 2;

            if (i >= len)
            {
                i = 1;
            }
        }
        
        std::cout << "s is: " << s << "\n";
        
        charCount.erase(current);
        current = std::begin(charCount);
    } while (current != std::end(charCount));

    return true;
}

int main()
{
    //char s[] = "hhhhhhhjsjsjksuwwuueueiiao";
    //char s[] = "xxxxxyyyy";
    //char s[] = "xxxxyyyyy";
    //char s[] = "xxxxxyyyyy";
    char s[] = "AABBBCCDD";

    if (fancyShuffle(s))
    {
        std::cout << s << "\n";
    }

    return 0;
}
