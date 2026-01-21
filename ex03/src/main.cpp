/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:08:11 by lcesbron          #+#    #+#             */
/*   Updated: 2026/01/20 18:30:33 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

static void printHeader(std::string const & title)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << "========================================" << std::endl;
}

static void subjectTest()
{
	printHeader("SUBJECT TEST (original)");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void testMateriaCloneAndType()
{
	printHeader("ICE & CURE: Clone and getType");

	Ice* ice = new Ice();
	Cure* cure = new Cure();

	std::cout << "Ice type: " << ice->getType() << std::endl;
	std::cout << "Cure type: " << cure->getType() << std::endl;

	AMateria* iceClone = ice->clone();
	AMateria* cureClone = cure->clone();

	std::cout << "Ice clone type: " << iceClone->getType() << std::endl;
	std::cout << "Cure clone type: " << cureClone->getType() << std::endl;

	delete ice;
	delete cure;
	delete iceClone;
	delete cureClone;
}

static void testMateriaCopyAndAssign()
{
	printHeader("ICE & CURE: Copy constructor and assignment");

	Ice original;
	std::cout << "Original Ice type: " << original.getType() << std::endl;

	Ice copied(original);
	std::cout << "Copied Ice type: " << copied.getType() << std::endl;

	Ice assigned;
	assigned = original;
	std::cout << "Assigned Ice type: " << assigned.getType() << std::endl;

	Cure cureOriginal;
	Cure cureCopied(cureOriginal);
	Cure cureAssigned;
	cureAssigned = cureOriginal;

	std::cout << "Original Cure type: " << cureOriginal.getType() << std::endl;
	std::cout << "Copied Cure type: " << cureCopied.getType() << std::endl;
	std::cout << "Assigned Cure type: " << cureAssigned.getType() << std::endl;
}

static void testMateriaSourceBasic()
{
	printHeader("MATERIA SOURCE: Basic learn and create");

	MateriaSource src;

	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	AMateria* ice = src.createMateria("ice");
	AMateria* cure = src.createMateria("cure");

	std::cout << "Created ice type: " << (ice ? ice->getType() : "NULL") << std::endl;
	std::cout << "Created cure type: " << (cure ? cure->getType() : "NULL") << std::endl;

	AMateria* unknown = src.createMateria("fire");
	std::cout << "Created unknown type: " << (unknown ? unknown->getType() : "NULL") << std::endl;

	delete ice;
	delete cure;
}

static void testMateriaSourceOverflow()
{
	printHeader("MATERIA SOURCE: Overflow test (more than 4)");

	MateriaSource src;

	std::cout << "Learning 5 materias (only 4 should be stored):" << std::endl;
	src.learnMateria(new Ice());
	std::cout << "  Learned ice (1)" << std::endl;
	src.learnMateria(new Cure());
	std::cout << "  Learned cure (2)" << std::endl;
	src.learnMateria(new Ice());
	std::cout << "  Learned ice (3)" << std::endl;
	src.learnMateria(new Cure());
	std::cout << "  Learned cure (4)" << std::endl;

	Ice* overflow = new Ice(); // TODO: delete this one
	src.learnMateria(overflow);
	std::cout << "  Tried to learn ice (5) - should be ignored" << std::endl;

	delete overflow;
}

static void testMateriaSourceCopy()
{
	printHeader("MATERIA SOURCE: Copy constructor (deep copy)");

	MateriaSource* original = new MateriaSource();
	original->learnMateria(new Ice());
	original->learnMateria(new Cure());

	MateriaSource copied(*original);

	delete original;
	std::cout << "Original deleted, testing copied source:" << std::endl;

	AMateria* ice = copied.createMateria("ice");
	AMateria* cure = copied.createMateria("cure");

	std::cout << "Copied source ice: " << (ice ? ice->getType() : "NULL") << std::endl;
	std::cout << "Copied source cure: " << (cure ? cure->getType() : "NULL") << std::endl;

	delete ice;
	delete cure;
}

static void testCharacterBasic()
{
	printHeader("CHARACTER: Basic equip, use, getName");

	Character alice("Alice");
	Character bob("Bob");

	std::cout << "Character name: " << alice.getName() << std::endl;
	std::cout << "Target name: " << bob.getName() << std::endl;

	alice.equip(new Ice());
	alice.equip(new Cure());

	std::cout << "Alice uses slot 0 on Bob:" << std::endl;
	alice.use(0, bob);

	std::cout << "Alice uses slot 1 on Bob:" << std::endl;
	alice.use(1, bob);
}

static void testCharacterOverflow()
{
	printHeader("CHARACTER: Overflow test (more than 4 materias)");

	Character player("Player");

	std::cout << "Equipping 5 materias (only 4 should be stored):" << std::endl;
	player.equip(new Ice());
	std::cout << "  Equipped ice (1)" << std::endl;
	player.equip(new Cure());
	std::cout << "  Equipped cure (2)" << std::endl;
	player.equip(new Ice());
	std::cout << "  Equipped ice (3)" << std::endl;
	player.equip(new Cure());
	std::cout << "  Equipped cure (4)" << std::endl;

	Ice* overflow = new Ice();
	player.equip(overflow);
	std::cout << "  Tried to equip ice (5) - should be ignored" << std::endl;

	delete overflow;
}

static void testCharacterUnequip()
{
	printHeader("CHARACTER: Unequip and unequipSavePointer");

	Character player("Player");
	Character target("Target");

	player.equip(new Ice());
	player.equip(new Cure());
	player.equip(new Ice());

	std::cout << "Initial state - 3 materias equipped" << std::endl;
	std::cout << "Using slot 0: ";
	player.use(0, target);
	std::cout << "Using slot 1: ";
	player.use(1, target);
	std::cout << "Using slot 2: ";
	player.use(2, target);

	std::cout << std::endl << "Unequipping slot 0 (ice):" << std::endl;
	AMateria* unequipped = player.unequipSavePointer(0);
	std::cout << "Unequipped materia type: " << unequipped->getType() << std::endl;

	std::cout << "Using slot 0 (should now be cure): ";
	player.use(0, target);
	std::cout << "Using slot 1 (should now be ice): ";
	player.use(1, target);

	delete unequipped;
}

static void testCharacterDeepCopy()
{
	printHeader("CHARACTER: Deep copy (copy constructor)");

	Character* original = new Character("Original");
	original->equip(new Ice());
	original->equip(new Cure());

	Character copied(*original);

	delete original;
	std::cout << "Original deleted, testing copied character:" << std::endl;

	Character target("Target");
	std::cout << "Copied character name: " << copied.getName() << std::endl;
	std::cout << "Using slot 0: ";
	copied.use(0, target);
	std::cout << "Using slot 1: ";
	copied.use(1, target);
}

static void testCharacterAssignment()
{
	printHeader("CHARACTER: Assignment operator (deep copy)");

	Character original("Original");
	original.equip(new Ice());
	original.equip(new Cure());

	Character assigned("ToBeReplaced");
	assigned.equip(new Cure());

	assigned = original;

	Character target("Target");
	std::cout << "Assigned character name: " << assigned.getName() << std::endl;
	std::cout << "Using slot 0: ";
	assigned.use(0, target);
	std::cout << "Using slot 1: ";
	assigned.use(1, target);
}

static void testPolymorphism()
{
	printHeader("POLYMORPHISM: Interface usage");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* player = new Character("Player");
	ICharacter* enemy = new Character("Enemy");

	player->equip(src->createMateria("ice"));
	player->equip(src->createMateria("cure"));

	std::cout << "Player (" << player->getName() << ") attacks Enemy (" << enemy->getName() << "):" << std::endl;
	player->use(0, *enemy);
	player->use(1, *enemy);

	delete enemy;
	delete player;
	delete src;
}

int main()
{
	subjectTest();

	testMateriaCloneAndType();
	testMateriaCopyAndAssign();

	testMateriaSourceBasic();
	testMateriaSourceOverflow();
	testMateriaSourceCopy();

	testCharacterBasic();
	testCharacterOverflow();
	testCharacterUnequip();
	testCharacterDeepCopy();
	testCharacterAssignment();

	testPolymorphism();

	std::cout << std::endl << "========================================"  << std::endl;
	std::cout << "  ALL TESTS COMPLETED" << std::endl;
	std::cout << "========================================" << std::endl;

	return 0;
}
