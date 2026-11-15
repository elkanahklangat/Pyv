# Learning to build an ML model that adapts to Kenyan lifestyle

# List of local Kenyan jobs
jobList = [           
           'House Wife', 
           'House Girl', 
           "Construction Laborer (Mtu wa mkono)",
           "Casual Worker(Kibarua)",
           "Handcart Pusher(Mtu wa Mkokoteni)",
           "Turnboy/Loader (Mtu wa kubeba mzigo)",
           "Mason(Fundi wan mawe)",
           "Carpenter(Fundi wa mbao)",
           "Welder(Fundi wa Kuchomelea)",
           "Painter(Fundi wa rangi)",
           "Motorbike Rider(Mtu wa bodaa)",
           "Minibus Conductor(Makanga/Manamba)",
           "Minibus Driver(Dereva wa matatu)",
           "Taxi Driver(Dereva wa Taxi)",
           "Bicycle Courier(Rider wa Baiskeli)",
           "House Help(Msaidizi wa boma)",
           "Laundry Assistant(Mtu wa Kufua Nguo)",
           "Car Washer(Mtu wa kuosha gari)",
           "Gardener(Mtu wa Sahmba)",
           "Garbage Collector(Mtu wa taka)",
           "Vegetable Vendor(Mama Mboga)",
           "Hawker/Street Trader(Mhuuzi)",
           "Scrap Metal Dealer(Mtu wa scrap)",
           "Charcoal Vendor(Mtu Makaa)",
           "Shoe Shiner(Mtu wa Kung'arisha Viatu)",
           "Shoe Repairer(Fundi wa viatu)",
           "Tailor(Fundi Wa Cherahani)",
           "Barber(Kinyozi)",
           "Hairdresser(Mtu wa salon)",
           "Security Guard(Soldier)",
           "Food Kiosk(Mtu wa Hoteli ya Kibanda)",
           "Web Developer",
           "Software Engineer",
           "Software Developer",
           "Website Designer(Web Designer)",
           "Mechanical Engineer",
           "Electrical Engineer",
           "Waiter",
           "Waitress",
           "Sheff(Cheff)"
           ]
job = input("Your job: ")
if job in jobList:
    print(f"You will get an employer looking for {job}! Hope for it")
else:
    print("Seems your job hasn't been updated. ")
ques = input("Are you really interested in working in hostile environments? How do you descibe your adaptations?")
quesList = ['I'm on right track', 'All is good', 'I believe I will adapt', Everything is alright', 'My peers keeps motivating me', 'I'm aware of myself']
if ques in quesList:
     print("Okay, I see you. Keep moving on At jobList, we keep the effort and thriving for more in innovation!) 
else:
    print("Alright, I'l get back to you later")
