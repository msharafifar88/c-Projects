// where we define a sale class
// Sale.h
// Mohammad Sharafifar
// 5/july/2019
//

#ifndef Sale_h
#define Sale_h

#include <vector>
#include "Product.h"

namespace sict {
    
    class Sale {
        std::vector<iProduct*> m_products;
        
    public:
        
        Sale(const char*);
        void display(std::ostream& os) const;
        
    };
}

#endif /* Sale_h */
