class galifrey =
object (self)
	val _dalekArmy =
		let d = new Dalek.dalek in
			(new Army.army d)#set_lst [d ; new Dalek.dalek ; new Dalek.dalek ; new Dalek.dalek ; new Dalek.dalek ; new Dalek.dalek ; new Dalek.dalek ]

	val _peopleArmy =
		let p = new People.people "People Soldier" in
			(new Army.army p)#set_lst [p ; new People.people "People Soldier" ; new People.people "People Soldier" ; new People.people "People Soldier" ; new People.people "People Soldier" ; new People.people "People Soldier" ; new People.people "People Soldier" ]

	val _timeLordsArmy =
		Random.self_init ();
		let tl = new Doctor.doctor "Generic Doctor" ((Random.int 500) + 200) (new People.people "Generic Companion") in
		(new Army.army tl)#set_lst [tl ; new Doctor.doctor "Generic Doctor" ((Random.int 500) + 200) (new People.people "Generic Companion") ; new Doctor.doctor "Generic Doctor" ((Random.int 500) + 200) (new People.people "Generic Companion"); new Doctor.doctor "Generic Doctor" ((Random.int 500) + 200) (new People.people "Generic Companion") ; new Doctor.doctor "Generic Doctor" ((Random.int 500) + 200) (new People.people "Generic Companion")]

	method private ppl_still_alive (army:People.people Army.army) =
		let rec loop army =
			match army with
			| head::tail -> if head#get_hp > 0 then true else loop tail
			| [] -> false
		in
		loop army#get_lst

	method all_doctors_use_screwdrivers (docs:Doctor.doctor Army.army) =
		docs#foreach (fun elem -> elem#use_sonic_screwdriver)

	method do_time_war =
		let dalek_attack_people army dalekn n = army#replace_elem ((List.nth _dalekArmy#get_lst dalekn)#exterminate (List.nth army#get_lst n)) n in

		print_endline "Dalek Army : " ;
		_dalekArmy#foreach (fun elem -> print_endline elem#to_string);
		print_endline "People Army : " ;
		_peopleArmy#foreach (fun elem -> print_endline elem#to_string);
		print_endline "Doctor Army : " ;
		_timeLordsArmy#foreach (fun elem -> print_endline elem#to_string) ;

		print_endline "Dalek attack : " ;
		let currentPeopleArmy = dalek_attack_people _peopleArmy 0 0 in
		let currentPeopleArmy = dalek_attack_people currentPeopleArmy 0 4 in
		let currentPeopleArmy = dalek_attack_people currentPeopleArmy 0 3 in
		print_endline "People Army after Dalek Attack " ;
		currentPeopleArmy#foreach (fun elem -> print_endline elem#to_string);

		if self#ppl_still_alive currentPeopleArmy then
			print_endline "There is at least a people still alive"
		else
			print_endline "all the people are dead.";
		let currentPeopleArmy = dalek_attack_people currentPeopleArmy 0 1 in
		let currentPeopleArmy = dalek_attack_people currentPeopleArmy 0 2 in
		let currentPeopleArmy = dalek_attack_people currentPeopleArmy 0 5 in
		let currentPeopleArmy = dalek_attack_people currentPeopleArmy 0 6 in
		print_endline "People Army after second Dalek Attack " ;
		currentPeopleArmy#foreach (fun elem -> print_endline elem#to_string);

		if self#ppl_still_alive currentPeopleArmy then
			print_endline "There is at least a people still alive"
		else
			print_endline "all the people are dead.";

		print_endline "WOW the doctors are angry ! They are using their screwdrier. Yes, that's totally useless." ;
		self#all_doctors_use_screwdrivers _timeLordsArmy;

		{<_peopleArmy=currentPeopleArmy>}
end
