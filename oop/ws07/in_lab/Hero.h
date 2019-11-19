/**********************************************************
 * Name:            Mohammad Sharafiafar
 * Student ID:        143473171
 * Seneca email:    msharafifar@myseneca.ca
 * Section:            SHH
 **********************************************************/


#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict
{
    const int max_rounds = 100;
    
    class Hero
    {
    private:
        char Name[41];
        int Health;
        int Attack;
    public:
        Hero();
        Hero(const char* g_name, int g_health, int g_attack);
        void operator-=(int p_Attack);
        bool isAlive() const;
        int attackStrength() const;
        const char* getname() const;
        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    };
    const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H


