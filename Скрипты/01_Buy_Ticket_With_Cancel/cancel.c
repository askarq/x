cancel()
{

	lr_start_transaction("click_itinerary");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);
	
	//считаем flightID при переходе на страницу просмотра квитанций
	
	web_reg_save_param("flightID_before",
		"LB=name=\"flightID",
		"RB=\"",
		"Ord=ALL",
		LAST);
	
	web_reg_find("Text=Web Tours Navigation Bar",
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t53.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_itinerary",LR_AUTO);

	lr_start_transaction("click_cancel");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(5);
	
	// Считаем flightID после операции отмены
	
	web_reg_save_param("flightID_after",
		"LB=name=\"flightID",
		"RB=\"",
		"Ord=ALL",
		LAST);
	
	
	// Параметр randomCancel имеет случайное значение от 1 до 3х, соответственно происходит отмена 1-3 билетов.
	
	if(atoi(lr_eval_string("{randomCancel}")) == 1 ) {
	web_submit_form("itinerary.pl",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=36", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
		LAST);
	}
	else if(atoi(lr_eval_string("{randomCancel}")) == 2 ) {
		
	web_submit_form("itinerary.pl",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=36", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
		LAST);
	}
	else {
	web_submit_form("itinerary.pl",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=3", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=36", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
		LAST);
	} 
	if (((atoi(lr_eval_string("{flightID_after_count}"))) < (atoi(lr_eval_string("{randomCancel}"))))) {
		
		lr_error_message("Ошибка, нехватает заказов для отмены");
	}
	
	// Проверка операции отмены.
	
	if(((atoi(lr_eval_string("{flightID_before_count}")))) < ((atoi(lr_eval_string("{flightID_after_count}"))/2))){
		
		lr_error_message("Операция отмена не работает");
		
	}
	   /* web_submit_data("itinerary.pl",
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t54.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=0-7-AI", ENDITEM, 
		"Name=flightID", "Value=0-15-AI", ENDITEM, 
		"Name=flightID", "Value=0-23-AI", ENDITEM, 
		"Name=flightID", "Value=0-30-AI", ENDITEM, 
		"Name=flightID", "Value=0-38-AI", ENDITEM, 
		"Name=flightID", "Value=0-46-AI", ENDITEM, 
		"Name=flightID", "Value=0-53-AI", ENDITEM, 
		"Name=flightID", "Value=210297416-6173-AI", ENDITEM, 
		"Name=removeFlights.x", "Value=36", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST); */

	lr_end_transaction("click_cancel",LR_AUTO);

	return 0;
}