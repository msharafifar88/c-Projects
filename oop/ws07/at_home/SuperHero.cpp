/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#include <iostream>
#include "SuperHero.h"


using namespace std;
using namespace sict;

namespace sict
{
    SuperHero::SuperHero() : Hero(){
        
        super_attack =0 ;
        super_def = 0 ;
        
    }
    SuperHero::SuperHero(const char* g_name, int g_health, int g_attack , int g_super_attack ,int g_super_def) : Hero(g_name ,g_health , g_attack)
    {
        
        super_attack = g_super_attack ;
        super_def = g_super_def ;
        
    }
    int SuperHero::attackStrength() const{
        
        if(super_attack > 0 && Hero::attackStrength() >0)
            return super_attack + Hero::attackStrength() ;
        else
            return 0;
    }
    
    int SuperHero::defend() const{
        
        if(super_def > 0)
            return super_def ;
        else
            return 0;
    }
    
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
        
        SuperHero left = first, right = second, winner;
        int round = 0;
        
        for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); ++i)
        {
            left -= right.attackStrength() - left.defend() ;
            right -= left.attackStrength() - right.defend();
            round = i;
            
        }
        round++;
        
        if (!left.isAlive() && !right.isAlive())
        {
            winner = left;
            cout << "Super Fight! " << first << " vs " << second
            << " : Winner is " << winner << " in " << round << " rounds." << endl;
            return first;
        }
        else if (!left.isAlive())
        {
            winner = right;
            cout << "Super Fight! " << first << " vs " << second
            << " : Winner is " << winner << " in " << round << " rounds." << endl;
            return second;
        }
        
        else if (!right.isAlive())
        {
            winner = left;
            cout << "Super Fight! " << first << " vs " << second
            << " : Winner is " << winner << " in " << round << " rounds." <<  endl ;
            return first;
        }
        else
        {
            return first;
        }
    }
    
 }
