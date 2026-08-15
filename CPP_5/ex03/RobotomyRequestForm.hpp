#include "AForm.hpp"


class RobotomyRequestForm : public AForm{
private:
  std::string target;

public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm const &other);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
  virtual ~RobotomyRequestForm();  

  virtual void exec_action() const;
};
