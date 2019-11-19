// its a base class of product 
// iProduct.h
// Mohammad Sharafifar
// 5/july/2019
//


#ifndef iProduct_h
#define iProduct_h


namespace sict {
    
    
    class iProduct {
        
    public:
        virtual double price() const = 0;
        virtual void display(std::ostream& os) const = 0;
        iProduct* readRecord(std::ifstream& file);
        
        
    };
    
    
    std::ostream& operator<<(std::ostream& os, const iProduct& p);
}



#endif /* iProduct_h */
