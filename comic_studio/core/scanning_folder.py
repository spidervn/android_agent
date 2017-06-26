# 
#	Scanning folder
#		input = folder
#	outut:
#		suggested command
#			1) Enter directories
#				
#				
# 			2) New command 
#				i) Finding suggested:
#					Comic
#					Related Chapters (Recursively)
#
#				ii) Suggested command
#					Add New comic
#					Update existing comic
#					Combine command (add+update)
#
#					Update chapter
#					Add new chapter
#					Combine command (add+update)
#
#					
#			3) UI
#				Inductive UI
#				
#	Output:
#		
#	Input:
#		

sm = {
	'ask(tasks: [ detecting directories ])'
	'do_action()',
	'ask(what do you want next: [ quit, next])',
	'do_action()', 
}

sm.define({
	start: show_ask_menu,
	do_action_handler_
})

start_up_menu(directory_examine, bulk_upgrade, exit) ----> switcher ---(id=directori_examinue)--> examine_directory 
																		--(id=bulk_upgrade)--> bulk_upgrade,
																		-- (id=exit)--> exit_app
	examine_directory --->
		---(output = invalid_dir) ---> menu(back_to_main_menu, quit),
		---(output = many_comics) ---> menu(back_to_main_menu, quit),
		---(output = one_comics/many_chaps) ---> menu(back_to_main_menu, quit),
		---(output = unrecognize) ---> input_type(type_of_menu), 
		---(output = invalid)---> quit_menu()
	bulk_upgrade ----> ask(quick_find, bulk_update, bulk_delete, back)
		---(output==back)---> main_menu()
		---(output==quick_find)---> ask_comic_name(auto_suggest=True) 
				---> menu(delete, update_field, quit)

	exit_app
		--- quit()--->

Q? 
	dynamic menu ? 
		=> by state machine definition ? 
		=> by state machine definition ? 
		=> by state machine ?

