/*
 ============================================================================
 Name        : KVList.h
 Author      : Mohammad Sharafifar
 Email       : msharafifar@myseneca.ca
 Student #   : 147473171
 Course Code : OOP345
 Section     : SBB
 Date        : may , 2019 -
 Workshop    : Workshop 5 - Lab
 ============================================================================
 */

/*
 ============================================================================
 Description : allocated list of T objects.
 we are creating a real object of array type of kVpair
 ============================================================================*/


#ifndef KVList_H
#define KVList_H

#include <iostream>
namespace sict {

  template <typename T>

  class KVList
  {

    T* List;
    size_t obj_size;
    size_t elemet_obj;

  public:
    //default constructor safe empty state
    KVList() {
        List= nullptr;
        obj_size =0;
        elemet_obj=0;
    } 
    //conctructor of KVList 
    KVList(int noOfObj)
    {

      if (noOfObj > 0)
      {
        obj_size = noOfObj;
        elemet_obj = 0;
        List = new T[noOfObj];
      }

      else
      {

        List = nullptr;
        obj_size = 0;
        elemet_obj = 0;
    
      }
    }

    //Move Conctructor
    KVList(KVList&& ListRef)
    {
      
      
        List = ListRef.List;
        obj_size = ListRef.obj_size;
        elemet_obj = ListRef.obj_size;

        ListRef.List = nullptr;
          ListRef.obj_size = 0;
          ListRef.elemet_obj = 0;
    
      
    }

    //Destructor
    ~KVList()
    {
      delete[] List;
      List = nullptr;
    }
    const T& operator[](size_t i) const
    {
      return List[i];
    }

    //function dispay()
    template<typename F>

    void display(std::ostream& os, F f) const
    {

      for (size_t i = 0; i < elemet_obj; i++)
        List[i].display(os, f);

    }

    //function push_back
    void push_back(const T& t)
    {

      if (elemet_obj < obj_size)
        List[elemet_obj] = t;
            ++elemet_obj;

    }

   
    KVList(const KVList&) = delete;

    KVList& operator=(const KVList&) = delete;

    KVList& operator=(KVList&&) = delete;

  };

}

#endif 
