#include "Serializer.hpp"

int main(){
  Data data;
  data.name = "larry";
  data.age = 25;
  data.height = 1.89f;

  std::cout << "--- Before Conversion ---\n";
  std::cout << "| Data name   : " << data.name << "\n";
  std::cout << "| Data age    : " << data.age << "\n";
  std::cout << "| Data height : " << data.height << "\n\n";
 
  uintptr_t cnv_to_int = Serializer::serialize(&data);

  std::cout << "--- Mid Conversion ---\n";
  std::cout << "Data cast as int : " << cnv_to_int << "\n\n";

  Data *regained = Serializer::deserialize(cnv_to_int);

  std::cout << "--- After Conversion ---\n";
  std::cout << "Data name   : " << regained->name << "\n";
  std::cout << "Data age    : " << regained->age << "\n";
  std::cout << "Data height : " << regained->height << "\n";
  return 0;
}
