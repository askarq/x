Action()
{	
	lr_start_transaction("UC_01_BuyTicket");
	
	lr_start_transaction("connect");

//	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Fail=NotFound",
		"Text=A Session ID has been created and loaded into a cookie called MSO.",
		LAST);
	
	web_reg_save_param("userSession",
		"LB=name=\"userSession\" value=\"",
		"RB=\"",
		LAST);
	

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("connect", LR_AUTO);

	lr_start_transaction("login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(5);

	web_reg_find("Fail=NotFound",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t17.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=36", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("click_flight");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);
	
	web_reg_find("Fail=NotFound",
		"Text=<title>Flight Selections</title>",
		LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click_flight",LR_AUTO);

	lr_start_transaction("click_find_flight");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(5);
	
	//web_reg_save_param("outboundFlight",
	//	"LB=name=\"outboundFlight\" value=\"",
	//	"RB=\"",
	//	"NotFound=ERROR",
	//	LAST);
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		"Ordinal=ALL",
		LAST);



	web_reg_save_param("flight_num",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=;",
		"Ord=ALL",
		LAST);
	
	web_reg_save_param("flight_time",
		"LB=<td align=\"center\">",
		"RB=m<td align=\"center\">",
		"Ord=ALL",
		LAST);


	// Flight departing from <B>Denver</B> to <B>Los Angeles</B> on <B>09/17/2020</B>
	
	web_reg_find("Text=Flight departing from <B>{depart}</B> to <B>{arrive}</B> on <B>{departDate}</B>",
		LAST);	
	
	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={numPass}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=48", ENDITEM, 
		"Name=findFlights.y", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("click_find_flight",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("choose_flight");
	
	web_reg_find("Text=<title>Flight Reservation</title>",
		LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t20.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight_2}", ENDITEM,
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=42", ENDITEM,
		"Name=reserveFlights.y", "Value=13", ENDITEM,
		LAST);

	lr_end_transaction("choose_flight",LR_AUTO);

	lr_start_transaction("fill_pay_info");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(5);
	
	//09/17/2020 :  8am : Flight 030 leaves Denver  for Los Angeles.<br>

	web_reg_find("Fail=NotFound",
		"Text={departDate} :  {flight_time_2}m : Flight {flight_num_2} leaves {depart}  for {arrive}",
		LAST);
	
	//3 Coach Class tickets from Denver to Paris.		
	
	web_reg_find("Fail=NotFound",
		"Text=<b><u>{numPass} {seatType} Class tickets from {depart} to {arrive}.</u></b>",
		LAST);
	
	// Параметр numPass задает кол-во пассажиров, и в в зависимости от кол-ва передается определенная форма.
	
	if(atoi(lr_eval_string("{numPass}")) == 3) {
	
	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t37.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={address1}", ENDITEM,
		"Name=address2", "Value={address2}", ENDITEM,
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM,
		"Name=pass2", "Value={firstName} {lastName}", ENDITEM,
		"Name=pass3", "Value={firstName} {lastName}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={randomMonth}/{randomYear}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight_2}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=24", ENDITEM,
		"Name=buyFlights.y", "Value=10", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

		}
	 else if(atoi(lr_eval_string("{numPass}")) == 4) {
		
	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t37.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={address1}", ENDITEM,
		"Name=address2", "Value={address2}", ENDITEM,
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM,
		"Name=pass2", "Value={firstName} {lastName}", ENDITEM,
		"Name=pass3", "Value={firstName} {lastName}", ENDITEM,
		"Name=pass4", "Value={firstName} {lastName}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={randomMonth}/{randomYear}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value={numPass}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight_2}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=24", ENDITEM,
		"Name=buyFlights.y", "Value=10", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
		
		}

	lr_end_transaction("fill_pay_info",LR_AUTO);
	
	
	cancel();

	lr_start_transaction("logout");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);
	
	web_reg_find("Fail=NotFound",
		"Text=A Session ID has been created and loaded into a cookie called MSO.",
		LAST);
	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("UC_01_BuyTicket",LR_AUTO);

	return 0;
}