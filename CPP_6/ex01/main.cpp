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
 
  // We convert Data to uintptr_t without loosing the data stored
  uintptr_t cnv_to_int = Serializer::serialize(&data);

  // Then we recast it back to Data to check if we lost the data or not
  Data *regained = Serializer::deserialize(cnv_to_int);

  // We print out the results to check for corruption in data
  std::cout << "--- After Conversion ---\n";
  std::cout << "Data name   : " << regained->name << "\n";
  std::cout << "Data age    : " << regained->age << "\n";
  std::cout << "Data height : " << regained->height << "\n";
  return 0;
}
