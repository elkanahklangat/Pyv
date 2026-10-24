# Learning to build an ML model that adapts to Kenyan lifestyle

my_foods = ['Pizza', 'Ugali', 'Pasta', 'Spaghetti']
friend_foods = my_foods[:]
print(f"\n My foods:  {my_foods}")
print(f"\n My fiend's foods: {friend_foods}")
# Adding my friend's food list
friend_foods.append(["Spainach", "Sukuma Wiki"])
# Adding my food list
my_foods.append(["Chapati", "Managu"])
print(f"2: {my_foods} \n 2f: {friend_foods}")
print("\n\n\n")
for mfood in my_foods:
    if mfood in my_foods:
        print(mfood)
    else:
        False

for ffood in friend_foods:
    if ffood in friend_foods:
        print(ffood)
    else:
        False
# Checking if certain food is both in my friend]s list and mine
print("\n\n")
for ifood in my_foods and friend_foods:
    if ifood in my_foods and ifood in friend_foods:
        print(f"{ifood} is both in my food and my friend's food. ")
    else:
        False
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