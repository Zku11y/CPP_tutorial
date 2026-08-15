#include "AForm.hpp"


class PresidentialPardonForm : public AForm{
private:
  std::string target;

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(PresidentialPardonForm const &other);
  PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
  virtual ~PresidentialPardonForm();  

  virtual void exec_action() const;
};
