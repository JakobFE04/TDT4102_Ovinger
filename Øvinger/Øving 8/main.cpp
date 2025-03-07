#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <iostream>



int main()
{
	std::shared_ptr<Person> Ask = std::make_shared<Person>("Ask", "ask@gmail.com");
	std::unique_ptr<Car> volvo = std::make_unique<Car>(3);
	std::shared_ptr<Person> Helga = std::make_shared<Person>("Helga", "helga@gmail.com", std::move(volvo));
	std::unique_ptr<Car> vW = std::make_unique<Car>(1);
	std::shared_ptr<Person> Jakob = std::make_shared<Person>("Jakob", "jakob@gmail.com", std::move(vW));

	Campus Gløs = Campus::trh;
	// std::cout << "Jakob's Campus: " << Gløs << std::endl;

	Meeting studieGruppe(28,15,16,Gløs,"Riot mot pointers", Jakob);
	studieGruppe.addParticipant(Ask);
	studieGruppe.addParticipant(Helga);
	// std::cout << studieGruppe.getDay() << std::endl;
	// std::cout << studieGruppe.getStartTime() << std::endl;
	// std::cout << studieGruppe.getEndTime() << std::endl;
	// std::cout << studieGruppe.getLocation()<< std::endl;
	// std::cout << studieGruppe.getSubject() << std::endl;
	// std::cout << *studieGruppe.getLeader() << std::endl;
	
	std::shared_ptr<Person> LL = std::make_shared<Person>("LL", "ll@gmail.com");
	std::unique_ptr<Car> audi = std::make_unique<Car>(3);
	std::shared_ptr<Person> Nome = std::make_shared<Person>("Nome", "nome@gmail.com", std::move(audi));
	std::unique_ptr<Car> porche = std::make_unique<Car>(1);
	std::shared_ptr<Person> Carl = std::make_shared<Person>("Carl", "carl@gmail.com", std::move(porche));


	Meeting MatteForelesning(28,14,17,Gløs,"Matte", Nome);
	Meeting EsdaIForelesning(28,15,16,Gløs,"Esda", LL);
	Meeting EsdaIIForelesning(30,15,16,Gløs,"Esda", Carl);

	std::vector<std::shared_ptr<Person>> forelesning_1 = studieGruppe.findPotentialCoDriving(EsdaIForelesning);
	std::cout << "ESDAI" << std::endl;
	for (auto& person : forelesning_1){
		std::cout << *person << std::endl;
	}

	std::vector<std::shared_ptr<Person>> forelesning_2 = studieGruppe.findPotentialCoDriving(EsdaIIForelesning);
	std::cout << "ESDAII" << std::endl;
	for (auto& person : forelesning_2){
		std::cout << *person << std::endl;
	}

	std::vector<std::shared_ptr<Person>> forelesning_3 = studieGruppe.findPotentialCoDriving(MatteForelesning);
	std::cout << "Matte" << std::endl;
	for (auto& person : forelesning_3){
		std::cout << *person << std::endl;
	}
	// It works!

	TDT4102::Point point{300,100};
	MeetingWindow vindu(point,1000,500,"Test");

	// const TDT4102::Point buttonPosition {100, 100};
    // const unsigned int buttonWidth = 100;
    // const unsigned int buttonHeight = 40;
    // const std::string buttonLabel = "Click me!";
    // TDT4102::Button button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};
	// button.setCallback(callbackFunction);
	// vindu.add(button);

	vindu.wait_for_close();
	return 0;
}
