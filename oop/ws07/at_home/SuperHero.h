/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict
{
    
    class SuperHero : public Hero
    {
    private:
        int super_attack;
        int super_def;
    public:
        SuperHero();
        SuperHero (const char* g_name, int g_health, int g_attack , int g_super_attack ,int g_super_def);
        int attackStrength() const;
        int defend() const;
        
        
    };
    const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H


