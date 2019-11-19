/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#include <iostream>
#include <cstring>
#include <string>
#include "Hero.h"


using namespace std;

namespace sict
{
    
    Hero::Hero()
    {
        Name[0] = '\0';
        Health = 0;
        Attack = 0;
    }
    
    Hero::Hero(const char* g_name, int g_health, int g_attack){
        
      bool valid_name = g_name != nullptr &&  g_name[0] != '\0';
        bool valid_health = g_health >0 ;
        bool valid_attack = g_attack >0 ;
        
        
        if (valid_name && valid_attack && valid_health){
            
            strcpy(Name, g_name);
            Health = g_health;
            Attack = g_attack;
            
        }else {
            
             *this = Hero();
            
        }
    }
    
    
    void Hero::operator-=( int p_attack){
        
        
        if(p_attack >0 && Health >0){
            
            Health -= p_attack ;
            
            if (Health <= 0){
                Health = 0;
            }
        }
        
    }
    
    
    bool Hero::isAlive() const{
        
        if (Health >0 )
            return true;
        else
            return false;
    }
    
    int Hero::attackStrength() const{
        
        if(Attack > 0)
            return Attack;
        else
            return 0;
    }
   //_________________________________________
    
    std::ostream& operator<<(std::ostream& os, const Hero& hero)
    {
        if (hero.Name[0] != '\n' && hero.Health != -1 && hero.Attack != -1)
            os << hero.Name;
        else
            os << "No hero";
        return os;
    }
    

    // _________________________________________

    const Hero& operator*(const Hero& first, const Hero& second)
    {
        Hero left = first, right = second, winner;
        int round = 0;
        
        for (int i = 0; i < max_rounds && (left.isAlive() && right.isAlive()); ++i)
        {
            left -= right.attackStrength();
            right -= left.attackStrength();
            round = i;
        }
        
        round++;
        
        if (!left.isAlive() && !right.isAlive())
        {
            winner = left;
            cout << "Ancient Battle! " << first << " vs " << second
            << " : Winner is " << winner << " in " << round << " rounds." << endl;
            return first;
        }
        else if (!left.isAlive())
        {
            winner = right;
            cout << "Ancient Battle! " << first << " vs " << second
            << " : Winner is " << winner << " in " << round << " rounds." << endl;
            return second;
        }
        
        else if (!right.isAlive())
        {
            winner = left;
            cout << "Ancient Battle! " << first << " vs " << second
            << " : Winner is " << winner << " in " << round << " rounds." << endl;
            return first;
        }
        else
        {
            return first;
        }
    }
    
 }
