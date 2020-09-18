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

	lr_think_time(15);

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

	lr_think_time(44);

	web_submit_data("itinerary.pl", 
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
		LAST);

	lr_end_transaction("click_cancel",LR_AUTO);

	return 0;
}