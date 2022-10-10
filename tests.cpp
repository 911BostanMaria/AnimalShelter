//#include "tests.h"
//#include "DynamicVector.h"
//#include "Shelter.h"
//#include "Repository.h"
//#include "User.h"
//#include "Service.h"
//#include <iostream>
//#include <cassert>
//
//void Test::testShelter()
//{   DynamicVector<Shelter> repo;
//    Shelter dog1 = Shelter("German Shepherd", "Bond", 1, "https://www.wowwow.ro/ciobanesc-german-caine/2145#");
//    Shelter dog2 = Shelter("Bulldog", "Yoda", 5, "https://www.wowwow.ro/bulldog-caine/2139");
//    assert(dog1.get_breed()=="German Shepherd");
//    assert(dog1.get_age()==1);
//    assert(dog1.get_name()=="Bond");
//    assert(dog1.get_link()=="https://www.wowwow.ro/ciobanesc-german-caine/2145#");
//    repo.addElement(dog1);
//    assert(repo.getSize() == 1);
//    repo.addElement(dog2);
//    assert(repo.getSize()==2);
//    dog1.set_breed("idk");
//    assert(dog1.get_breed()=="idk");
//    dog1.set_name("maria");
//    assert(dog1.get_name()=="maria");
//    dog1.set_age(1);
//    assert(dog1.get_age()==1);
//    dog1.set_link("link");
//    assert(dog1.get_link()=="link");
//    dog2.set_breed("idkk");
//    assert(dog2.get_breed()=="idkk");
//    dog2.set_name("mariaa");
//    assert(dog2.get_name()=="mariaa");
//    dog2.set_age(1);
//    assert(dog2.get_age()==1);
//    dog2.set_link("linkk");
//    assert(dog2.get_link()=="linkk");
//}
//
//void Test::testDynamicVector(){
//    DynamicVector <Shelter>v(2);
//    Shelter dog1 = Shelter("German Shepherd", "Bond", 1, "https://www.wowwow.ro/ciobanesc-german-caine/2145#");
//    Shelter dog2 = Shelter("Bulldog", "Yoda", 5, "https://www.wowwow.ro/bulldog-caine/2139");
//    Shelter dog3 = Shelter("German Shepherd", "James Bond", 1, "https://www.wowwow.ro/ciobanesc-german-caine/2145#");
//    assert(v.getCapacity() == 2);
//    assert(&(v = v) == &v);
//    assert(v.getSize() == 0);
//    v.addElement(dog1);
//    assert(v[0].get_name() == "Bond");
//    assert(v.getSize() == 1);
//    v.addElement(dog2);
//    assert(v.getSize() == 2);
//    v.addElement(dog3);
//    assert(v.getSize() == 3);
//    v.removeElement(0);
//    assert(v.getSize() == 2);
//    DynamicVector<Shelter> copy;
//    copy = v;
//    assert(copy.getSize() == v.getSize());
//    }
//
//void Test::testRepository() {
//    Repository r;
//    bool exceptionThrown = false;
//    Shelter e("idk" , "idk" ,1 , "idk");
//    r.add_pet(e);
//    Shelter e2("idk" , "idk" ,1 , "idk");
//    try {
//        r.add_pet(e2);
//    } catch(std::invalid_argument&){
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//    assert(r.find_by_name(e)==1);
//    std::vector<Shelter>list;
//    list = r.getData();
//    assert(r.filter("idkggf",1).size()==0);
//    r.delete_pet("idk");
//    assert(r.getSize() == 0);
//    exceptionThrown = false;
//    try {
//        r.delete_pet("a");
//    } catch(std::invalid_argument&){
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//    Shelter e3("idk" , "idk" ,1 , "idk");
//    r.add_pet(e3);
//    r.update_info("idk","mama",10,"link");
////    assert(e3.get_age()==10);
//   // assert(e3.get_link()=="link");
//    exceptionThrown = false;
//    try {
//        r.update_info("geany","mama",10,"link");
//    } catch(std::invalid_argument&){
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//    r.add_ten_pets();
//    assert(r.getSize()>10);
//    User u;
//    Shelter new_pet("Maria","super",10,"l");
//    r.add_pet(new_pet);
//    u.user_adopt(new_pet);
//    assert(u.getData().size()==1);
//    exceptionThrown = false;
//    try {
//        r.delete_pet("Maria");
//    } catch(std::invalid_argument&){
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//    Shelter new_pet2("Maria","super",10,"l");
//    try {
//        u.user_adopt(new_pet2);
//    } catch(std::invalid_argument&){
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//
//
//
//
//}

//void Test::testService(){
//    Repository r;
//    User u;
//    Service s(r,u);
//    assert(&(s.getData() = s.getData()) == &s.getData());
//    Shelter pet("Maria","super",10,"l");
//    s.service_add((string &) "Maria", (string &) "super", 10, (string &) "l");
//    assert(s.getData()[0].get_name()=="Maria");
//    s.service_delete("Maria");
//    bool exceptionThrown=false;
//    try {
//        s.service_delete("Maria");
//    } catch(std::invalid_argument&){
//        exceptionThrown = true;
//    }
//    assert(exceptionThrown);
//
//}
//
//
//void Test::testall(){
//    testShelter();
//    testDynamicVector();
//    testRepository();
//    testService();
//}