//
// Created by 张睿 on 2022/5/20.
//

#ifndef VLIANG_CHINESE_CHESS_ZOBRIST_CODE_H
#define VLIANG_CHINESE_CHESS_ZOBRIST_CODE_H

const static double hash_code[][] =
        {{0.8935732324318227,   0.6454703993387576,  0.8748193419632603,  0.8789941084896745,  0.011004786432475155, 0.33590142300586,    0.703243366171727,   0.08035587146881351,  0.5452605946361984,   0.5310614326329122,   0.07108915604947108, 0.43488277091494676,  0.8028874488589336,  0.012304846651074786, 0.34411510515615606,  0.8227400024566094,   0.45992758799490896,  0.9128311325305658,  0.43617409622508685,  0.28606248536448153, 0.3164615228594677,  0.7618999230088502,  0.3296717639155008,  0.23769452674371927,  0.27500599488862676, 0.10267050915483822, 0.3056126540241273,   0.7220847174178298,    0.31330509010417673,  0.1683158154874974,  0.47457390461649385, 0.6470683012483261,  0.8714673117725829,  0.7895367134088397,  0.9899838348894254,  0.35936973430597796,  0.2540646907911295,  0.17632963858676254, 0.146373469904862,    0.6720106166143741,  0.3597245983451378,  0.46783687437132837, 0.4178067272874738,  0.46840934396812073, 0.29390909226097317, 0.9763353664125887,  0.37548484175172403, 0.30581001678964914, 0.1949898551903061, 0.8648964390608995, 0.3385596544880807, 0.019780787641785702, 0.9093919601269755, 0.5929756047962028, 0.558478661894197, 0.19187214396299057, 0.9884931610931608, 0.8401680934963915, 0.7147251821172791, 0.48412788447176913, 0.8481291508920069, 0.7755919576305675, 0.5086045323791059, 0.26699325310112143, 0.8309701178767194, 0.4788378692471269, 0.18176730302070343, 0.6712655750521137, 0.34269743653403084, 0.038150615832202917, 0.857449254885782, 0.18008510527771837, 0.19482331986917467, 0.3524842685315096, 0.7049469011825212, 0.1435644913778117, 0.7801607004065783, 0.9462993540268357, 0.06163621324678603, 0.14650789148579058, 0.7313645374111031, 0.1694470344093416, 0.8118819428970049, 0.9887712605362081, 0.2686295581190029, 0.9992119449686909, 0.5184728186128602, 0.14816744001837334, 0.529543800898092, 0.28756149598392744},
         {0.029758519289574403, 0.9874214750885923,  0.7922612548562783,  0.7038766312772979,  0.544451733439654,    0.6395325320941581,  0.6525712328528123,  0.8119150183017801,   0.4060990319222022,   0.4600008065039536,   0.8961054575270084,  0.6894845378417584,   0.22051251807104932, 0.16972919721125335,  0.018838716042228087, 0.2502815539212244,   0.24199366793175303,  0.3290111722436475,  0.09220268144070276,  0.9595744782118326,  0.3579696768669457,  0.5808677160481528,  0.9435464777241692,  0.9488907289801621,   0.4167016874041479,  0.18109784264088247, 0.42834139458608056,  0.6295903736019166,    0.08901350178117406,  0.6927588522178154,  0.9074421474255362,  0.7811877066034558,  0.9325283043544771,  0.36439379467674327, 0.9108798910109457,  0.747507521760432,    0.8356898617007555,  0.6341754653770278,  0.3690773459846206,   0.8122399103029069,  0.5588840490944004,  0.4062376830844011,  0.7230396096747457,  0.04518394178127949, 0.661265372705072,   0.23081591523824596, 0.6869889683790409, 0.911447006672477, 0.7044322219936039, 0.28642157942103297, 0.4300756848005516, 0.718093114066266, 0.25788392619281464, 0.11012507370995805, 0.46821077686531865, 0.5362104460985665, 0.8962311401521391, 0.35112467817574766, 0.6127312923388657, 0.5810942297564452, 0.07442106218934097, 0.43312988370398864, 0.9095219528615363, 0.15921856590722694, 0.49477709246421686, 0.9026893515210401, 0.620381928747279, 0.19789635079767143, 0.33844230634333705, 0.4134450061643049, 0.9478386934856776, 0.06200387504308702, 0.5238547120408618, 0.7503957443254881, 0.38527585142226006, 0.831872706717013, 0.9761718014632226, 0.03360530759122904, 0.28615504669567704, 0.46742833843735454, 0.7441004058005191, 0.2573910898695386, 0.4892769585481286, 0.3158812238015196, 0.6843773744539386, 0.6188812288045163, 0.61143948072571, 0.23375324290676947, 0.3491856023490839, 0.6689301837512598},
         {0.9245164345570427,   0.18874777352631555, 0.6580784812632643,  0.1787332284256613,  0.5708930166863017,   0.5829498874239663,  0.9135258975426982,  0.7570829654559028,   0.2393592079970548,   0.6960681241647982,   0.7279829397303021,  0.6760617069013385,   0.3229756956942713,  0.5859070015982855,   0.47042218085195187,  0.06706578663718343,  0.011091719365417974, 0.5029852239889492,  0.9115591984190856,   0.6344086865047271,  0.7296072019495035,  0.3771916641987155,  0.8495402615050894,  0.3003524273428376,   0.836737068055942,   0.21659753922221603, 0.6316498352631084,   0.7432671390465664,    0.5059480629472798,   0.32201943929348864, 0.6526350700782779,  0.6197210890550704,  0.28340387951538504, 0.0656552167140011,  0.10653301175198893, 0.37165473592158726,  0.8941676878274166,  0.6080904049804654,  0.4964257980483441,   0.9113937610545805,  0.48957508841755326, 0.33520004036737816, 0.6653378372563911,  0.15010791967275283, 0.677605553290232,   0.9849471126577973,  0.4015281180312614, 0.2894239878131042, 0.3587429416971898, 0.4038053328908814, 0.9927200190451242, 0.03125251290540487, 0.6017315522114292, 0.6235107122247462, 0.456349735463088, 0.37748966489115876, 0.5367963650982607, 0.4810725095134675, 0.5567039388550599, 0.48910747153890566, 0.5183120006504338, 0.31845164624059896, 0.13485569011811682, 0.15324654086864098, 0.6145671982443975, 0.3930398913411123, 0.7235976284253373, 0.7672775884459423, 0.8191874897476267, 0.5060509919693649, 0.8971094421541019, 0.3903992837529594, 0.24694112151113612, 0.01316062655517336, 0.31388664329546145, 0.336191702313015, 0.9760686982253989, 0.820208831986451, 0.9514961238264193, 0.9836459756568715, 0.1299400255768728, 0.18650554319781698, 0.6030131806188957, 0.9695426126530508, 0.25275662765995166, 0.15925570992326177, 0.30753411822089594, 0.6916523353971592, 0.0271816394815958, 0.24484750607315997},
         {0.02094677556788216,  0.10008477151592432, 0.9061933836893504,  0.4862237978950784,  0.4981814132023915,   0.0832121065010194,  0.28712292220115354, 0.46028316856464935,  0.054452661310768424, 0.3649462434004712,   0.44274965985094994, 0.8352336012201648,   0.6005426311585461,  0.7217495749951774,   0.542493413545729,    0.03504877385371663,  0.10596428359976673,  0.5006110411666768,  0.7461554420944708,   0.24665268541442464, 0.43388332429680776, 0.8733207960256291,  0.5333247439164763,  0.4751859186919727,   0.31296582398242767, 0.9977281580882732,  0.14348003850978208,  0.603682571444522,     0.06385763723983018,  0.2732694713312801,  0.24498255088305243, 0.44571373304630213, 0.5817914834450717,  0.1759034261961714,  0.7255674233244463,  0.5930302767732103,   0.991855516895423,   0.7366938703548728,  0.8026072032816786,   0.45496361973712385, 0.33974737305088376, 0.5886305732070216,  0.48833372241640005, 0.262320372508298,   0.6583759215234313,  0.6478811616975607,  0.8133693498284632, 0.965732850926982, 0.7594624579071083, 0.9185177944518448, 0.11133258352766584, 0.8969041608488676, 0.13933205251353464, 0.6138650783139471, 0.09794673020052547, 0.7809133071407661, 0.45937469159669164, 0.7729657725147758, 0.4399948784448606, 0.18872193999772435, 0.16419502354343962, 0.8172636184300722, 0.002628302832553442, 0.8012514545090496, 0.9342587352547476, 0.04045378137182376, 0.9879490391259382, 0.9198749234807871, 0.8348821619948097, 0.8535525193166507, 0.7334523434481738, 0.5028960619826813, 0.21970145057925605, 0.7175899493007222, 0.025828050355838128, 0.6335626841848498, 0.6742961114272467, 0.08793116864714212, 0.4037841140883506, 0.7323897020560558, 0.544431225680243, 0.36708178836055316, 0.07296979579125118, 0.015042742208491555, 0.8834212205603111, 0.8169370705525661, 0.7367400621299941, 0.6667602312733917, 0.9744078073445924, 0.6167835042964726},
         {0.8584164297998845,   0.9552682338927878,  0.935883096991252,   0.7699650170125826,  0.6138641863099011,   0.03636886775015147, 0.30257837824576994, 0.35997620211880066,  0.06761938999805006,  0.51986012466441,     0.8888779824617881,  0.7358473275639091,   0.9114633429826914,  0.9581706223996753,   0.6882066197308372,   0.5670372106391626,   0.44125643069711606,  0.29607022343272926, 0.039377924759157135, 0.349651375020823,   0.31600722648541046, 0.9770437234489043,  0.7996805955715831,  0.8686549019832642,   0.04256640554355606, 0.8403909917869347,  0.8045180379863277,   0.32485064843010814,   0.059999834090366466, 0.16284414111055467, 0.46470602594879573, 0.32074502819731043, 0.7596086042462264,  0.199468651603944,   0.9550722807720062,  0.6660255486034542,   0.7697281121659683,  0.36084133790555595, 0.08179092861753567,  0.01122507762752356, 0.35885252813780055, 0.7269758748857565,  0.5809236194722379,  0.647250353714183,   0.8662944673672607,  0.9431917463838873,  0.29692820397301256, 0.4188027998496364, 0.6565045890890254, 0.6691000751492904, 0.41743538591384755, 0.5913223193333107, 0.211339115147409, 0.6591059730777542, 0.699382014305056, 0.6839351112551769, 0.6239777580837603, 0.2413035916379327, 0.4116295104670017, 0.7349894472493685, 0.938858658839184, 0.43136634219394887, 0.5404845265102023, 0.20211359712664334, 0.4939105809182375, 0.16901237427371285, 0.6570781792268183, 0.7153328352929275, 0.6645271919726634, 0.19685038299856483, 0.7293491889243552, 0.1996329638694171, 0.18314183320166266, 0.9148888571222997, 0.07641530389646234, 0.4624603138736012, 0.5139258625927885, 0.1387173288863256, 0.6094066868619453, 0.20199884349702946, 0.5990468223396654, 0.06534568044379474, 0.4803735857418503, 0.5336672889010555, 0.6610876914318887, 0.9079131799336345, 0.2696699784925458, 0.555130581331309, 0.6456419290526817, 0.5989564333892632},
         {0.8822539570911764,   0.17422089330076895, 0.31876329212817034, 0.6816510616514765,  0.3946344438821625,   0.40951613172034573, 0.9958634035613574,  0.009419488820107347, 0.1967332041011225,   0.6399243279209698,   0.3718142480923804,  0.15652269250760198,  0.9067197499958289,  0.8274746256805724,   0.9464266588137704,   0.5057314077840281,   0.7019163978007735,   0.5666168607421448,  0.09514001028047703,  0.8238977748905097,  0.9051592633230494,  0.9236830870653867,  0.9216724707673286,  0.7622260670810653,   0.8935401084984549,  0.4217663726361237,  0.6475448991111663,   0.125266831512015,     0.6552436054721409,   0.1991236285764182,  0.4428062014402734,  0.9411356819796594,  0.6102326803852234,  0.3233102985657459,  0.282951156742521,   0.33518459249356325,  0.6318244292641757,  0.4786073434495399,  0.628936417492742,    0.9603301382865455,  0.5587380108068065,  0.7609013681843745,  0.47036449138551106, 0.2694693135720445,  0.8709846157918043,  0.11203105276837722, 0.5463188784912867, 0.22889075367635725, 0.6180090141801761, 0.00471444921168207, 0.3639984249471103, 0.16631498910923803, 0.13378136485443115, 0.34952311678683234, 0.9722125730906098, 0.3231747707260446, 0.5510766264306808, 0.23697063677464936, 0.3149633119861035, 0.33797220541909034, 0.6359681929705094, 0.05063492469879327, 0.3897536953300248, 0.3260267835163676, 0.0036014463473381664, 0.691334854837301, 0.3659269000678026, 0.44065427772199106, 0.34760215491623436, 0.13773371244300137, 0.2802539487057598, 0.8017935269054404, 0.9180132215317002, 0.3353432097656659, 0.9201519940269918, 0.460324572702443, 0.11644274257565546, 0.4537535390480826, 0.029329435295063155, 0.6297978950604631, 0.742145461602405, 0.8810165484160014, 0.026318071873569382, 0.7620215184182584, 0.11904833746723265, 0.9344603765795227, 0.013266376032194827, 0.16892892382641778, 0.06127052789186316, 0.15881608081315968},
         {0.9705326458182025,   0.8003774792091602,  0.3934767228859225,  0.25538748109191733, 0.6820298225547172,   0.4760036258696082,  0.532442072515256,   0.14009773587397023,  0.11693901498678949,  0.33898761737331085,  0.4574959567089103,  0.3635975435406599,   0.7053218078858449,  0.5505570331952104,   0.2500508242488074,   0.1432210878907778,   0.1883262405539462,   0.27628522473344985, 0.2662116116151758,   0.5544278104081422,  0.49809493990907217, 0.8287168053632907,  0.9214999458969954,  0.008469574384072032, 0.42814804201837653, 0.4255795937071003,  0.013016855130364213, 0.0033741440074070983, 0.6919279072525838,   0.3988184227263305,  0.4819063405652726,  0.2769377312806405,  0.33535633359163497, 0.8469127843426553,  0.5277715029070166,  0.9132706965060661,   0.3686689834960504,  0.661417509277231,   0.026734004858095184, 0.6585421883779219,  0.9134563303911389,  0.5783913196829003,  0.2761162866836345,  0.6869211750840037,  0.12275388755860672, 0.4063552522767724,  0.1912658287705694, 0.32431235221666754, 0.6251887869467464, 0.8646495160950707, 0.2138287162017941, 0.7853380071892304, 0.26860416813700194, 0.5295333961942741, 0.355820052052223, 0.8081170648371732, 0.49424606674375837, 0.23010017545519745, 1.2662006258934433E-4, 0.1817456738780504, 0.7595125371079429, 0.8620548153833355, 0.30561744153508696, 0.5529836945324087, 0.045428104500562116, 0.9946292191659694, 0.32382572244987995, 0.5715044531486805, 0.6344210142898168, 0.83438623988395, 0.2242058387888477, 0.38716556709369976, 0.02464462462764616, 0.0793903410731509, 0.34625743755917027, 0.7481108040015828, 0.058998658655102565, 0.9481990419153249, 0.14934785202261214, 0.4651144246302862, 0.09016968501678568, 0.20035620710572266, 0.514853275912498, 0.8054307597955187, 0.2774246813334307, 0.27854463509895844, 0.27027830434314337, 0.45851370869970265, 0.9165551107728044, 0.7972819881321397},
         {0.25130182833132164,  0.07632227105994216, 0.04128352923208645, 0.4790205206361755,  0.6952375475652366,   0.03252924307159799, 0.40260856666174516, 0.2957379401223883,   0.26818492291346196,  0.9678031867077063,   0.33197781657030334, 0.012583182302385865, 0.5681869482102867,  0.8924333736322578,   0.9248431383616619,   0.5498669745704293,   0.5179989431378286,   0.10292080635812084, 0.44306583471517313,  0.5806645871885846,  0.6636125729323329,  0.9357589395867727,  0.8278041787404429,  0.5635236575952278,   0.02846762677150183, 0.42947929783356276, 0.7389293760544858,   0.9732476223344289,    0.8383237301849191,   0.29513937933527534, 0.5926798794649478,  0.837450662631343,   0.1280527583860006,  0.2057812776181267,  0.6561786395472317,  0.8125577829769546,   0.9691522687081836,  0.3069909055959339,  0.37560170414547867,  0.9401493162929538,  0.815568695177691,   0.02353993029790269, 0.7641999313353363,  0.9130264202075262,  0.2554589543733924,  0.6911933288226065,  0.8570412103750888, 0.15009995684848976, 0.2778072059543928, 0.27811758479176074, 0.9512528610021335, 0.23018248378147255, 0.015353414560195788, 0.4769257689636497, 0.5937091957020803, 0.26698888645077423, 0.8090789280615908, 0.7462474586683538, 0.05252303743379283, 0.621128567061901, 0.3545335171184054, 0.45981320131043424, 0.31436343412486734, 0.9395977334173986, 0.6365773782179203, 0.1813942275878978, 0.4865366593953999, 0.8892577949613728, 0.3366506656389925, 0.22554042665934892, 0.8509314820399422, 0.10801178963939395, 0.40547211260598026, 0.08691034723127933, 0.7163430271296501, 0.8358676226332525, 0.5341073921761637, 0.025089508393394078, 0.6463547829792189, 0.40780340018324235, 0.3276371137491728, 0.07714377730446831, 0.6018714669474003, 0.29132678030260784, 0.0881930511423824, 0.03675711024495343, 0.030559886965815353, 0.6338466348881676, 0.24792061954101297, 0.4866538040127868},
         {0.9598688813825537,   0.3484519460785368,  0.6574644053001251,  0.8001076208836521,  0.705963706728548,    0.6114197139045173,  0.13186280723373467, 0.13769085646217172,  0.8978239474939465,   0.27074977864076877,  0.8832769001216572,  0.8570189088728225,   0.13391844033968214, 0.07225114130369514,  0.7287673912904428,   0.4260968569197908,   0.7382845260639982,   0.7981812865231872,  0.2513731864726235,   0.8849762886646837,  0.7635029409551818,  0.383165966551391,   0.41403349575357506, 0.13578221645798572,  0.5999743266285367,  0.8231040988318976,  0.47843494866105596,  0.8577714741225262,    0.2940662749807116,   0.22498841854721163, 0.4646540611995985,  0.6419356061319692,  0.9521151750207214,  0.6590495172629381,  0.8025044115430787,  0.018762510021944956, 0.4129301375839245,  0.5693571904614269,  0.2717870202728335,   0.41312314420647256, 0.7083610252210254,  0.3749899664113223,  0.8061816805844626,  0.7018508992258663,  0.6996562021524154,  0.5511094189062589,  0.24430540501078413, 0.9724326750963546, 0.6767501292514241, 0.9177536998847685, 0.6515042662175667, 0.28533250458127624, 0.6382845585278133, 0.08388991134391122, 0.4072327615148984, 0.7278200562078492, 0.43208145475168624, 0.9952426101818048, 0.8554149687445597, 0.8137779142411783, 0.9289497114961631, 0.3166416429170239, 0.9489700426297164, 0.3318130165867541, 0.9271217118218528, 0.9431093963505756, 0.9847242739607838, 0.07309914003232698, 0.5402801528040397, 0.2786338605369132, 0.22122028712910724, 0.480729421603853, 0.40904913092286155, 0.047550719699000155, 0.8994738902345701, 0.1539583897263318, 0.19398801543344668, 0.31068409108676454, 0.9455172784242921, 0.313565842859998, 0.45754043537579103, 0.04687208748255001, 0.42360713763311353, 0.7886754326573905, 0.2230547861520401, 0.13023013080481738, 0.6302644689406133, 0.8207128279568899, 0.21090696398716635, 0.7844811171920357},
         {0.5718529017871005,   0.996789903041271,   0.9949195329176663,  0.6279085287715465,  0.45219037062832834,  0.9226530002839842,  0.09668648419834724, 0.23596510763218492,  0.711729094051699,    0.8244343675348099,   0.3410757796159455,  0.7432955596094919,   0.106126779710774,   0.1287984207204601,   0.6330968226497959,   0.38290959176514516,  0.2895721294909268,   0.2126748664689938,  0.6844834325558263,   0.01746699715406741, 0.3770158945741483,  0.9366233190509399,  0.11775742887515117, 0.6561135516405332,   0.9994983567924254,  0.2799749415594053,  0.8062016751350063,   0.6700332280963822,    0.43805282156212655,  0.38124847053170463, 0.2700854535013213,  0.9208581566506778,  0.5242040335960443,  0.5539394944486534,  0.44264958527743026, 0.29830538405705354,  0.12886943072201085, 0.3956334967694449,  0.14377216609688015,  0.22688466817977715, 0.22650986329964917, 0.9374945559397937,  0.15490020579024844, 0.5462493812693365,  0.7176661382220147,  0.891533329096392,   0.8757464505071709, 0.7957383793361965, 0.4205562770436254, 0.4446594518363889, 0.16141471048373623, 0.34088353887996536, 0.9011975104311598, 0.7213750316474797, 0.08803110596085506, 0.968134270089531, 0.10155621454496788, 0.99106748250112, 0.07562265697187731, 0.5437765383861626, 0.0465182738319635, 0.9312114383902198, 0.008898684335728824, 0.08400106023714504, 0.2630107902703084, 0.7743913561794379, 0.7397547529302776, 0.11530144737127623, 0.9283957375161053, 0.9649074809379778, 0.6297326887260939, 0.5178596161932931, 0.18029499349954092, 0.029829739069324512, 0.5963342980924625, 0.13930274142085308, 0.46629504106989805, 0.7297158476618445, 0.4640007966442792, 0.34219216305753763, 0.2895191142432, 0.19581090141333435, 0.28873351269438907, 0.30583168230316016, 0.21484330165497423, 0.6833979775916597, 0.724746000053824, 0.3414584293189209, 0.5405722016496459, 0.7750701578701107},
         {0.4322012052208696,   0.6996072619674444,  0.6116790954427572,  0.3530467092464208,  0.9870020945989237,   0.3494149744869295,  0.3532541185831424,  0.4262568653747111,   0.7467675952829642,   0.9918581374991682,   0.23659351857148203, 0.9457669529630806,   0.651539805108418,   0.1323941324795158,   0.5554019849188189,   0.07122765439319378,  0.993433213866619,    0.38320237170473803, 0.5858687486942725,   0.9613702672797091,  0.7763496146604735,  0.29119845598076355, 0.9319177445989552,  0.05318169403370321,  0.4050474211101237,  0.8952209781596708,  0.11572091108058535,  0.9672401922297671,    0.09226772584727316,  0.9042674000722655,  0.2636026564471635,  0.6307948233816993,  0.5532832924873128,  0.8583814818956876,  0.5587529542726902,  0.9455238997284972,   0.26915139288921774, 0.8847719440862883,  0.9847052277180682,   0.34350813345472964, 0.8431148084348549,  0.6939679490460942,  0.7673242424019492,  0.8728070511610843,  0.7490096881595016,  0.2742939868423391,  0.8380888746667947, 0.03312779489148798, 0.07620295673952227, 0.337673465656939, 0.5877426958264338, 0.44242753411230074, 0.7124961727365684, 0.9457461173576587, 0.15692532992697017, 0.5568921255524905, 0.7745964815581117, 0.9025116903466653, 0.5191860456336126, 0.08958494599554467, 0.9951696314028539, 0.4381887079519686, 0.6518202225425784, 0.4771621641558902, 0.2061540895515821, 0.42870325985606816, 0.16125842855041883, 0.7294012953553127, 0.019929095838164712, 0.8962000137933822, 0.832277051608047, 0.26289206450072766, 0.3030939289624678, 0.8181936498195318, 0.7040882396039189, 0.8680901089759787, 0.06202944308596969, 0.3364557564192274, 0.4414058378008783, 0.7880354795435901, 0.9150769211491343, 0.3014586944824553, 0.9648739831649531, 0.9973893038122137, 0.41308386009617537, 0.71417456818269, 0.5327824874966864, 0.16204422752923442, 0.08822973805419398, 0.034253853605776596},
         {0.7247840024650651,   0.43241467659778987, 0.2604592304546679,  0.5120852014643166,  0.0683654890270814,   0.1776156702114693,  0.31151435529793536, 0.6719636463493422,   0.37011655254761167,  0.003089928941648501, 0.34847103957699443, 0.824572199974253,    0.16637586401154958, 0.9108444620654991,   0.9218497434060864,   0.019207303122130592, 0.09162614889743015,  0.2593097603930098,  0.7377836980142747,   0.15965579442322664, 0.3780467772569376,  0.2589359275424714,  0.10939244059825004, 0.10235727125791172,  0.14592302178840777, 0.09999199943846859, 0.22942267798304017,  0.4314627422398878,    0.6221490038271703,   0.4506360770669203,  0.21438189002129726, 0.26262630512938656, 0.9328512733172017,  0.9861751484506616,  0.26980489175831246, 0.8658439853712299,   0.6561985897215821,  0.8145357497958441,  0.2569571730953485,   0.11737976910880799, 0.8927524852060669,  0.148317618025253,   0.40319307374226976, 0.7917956148757042,  0.2132528228081101,  0.34040406520346345, 0.8913509548014011, 0.48732927886889843, 0.4775206500145237, 0.44795490006595584, 0.5879811387401948, 0.5413392771160698, 0.18320085790030505, 0.8187082766296289, 0.2258674290404291, 0.6372640188594229, 0.6993550769852743, 0.8038708581967883, 0.9432159131776033, 0.9305182345901131, 0.4674552690866025, 0.5934756037366928, 0.2000497893203672, 0.4279757198922002, 0.011117048306552912, 0.34293943701534424, 0.7417623086477979, 0.04416561108704675, 0.3859506124304898, 0.21365384644017338, 0.4604443481769329, 0.22703391034139508, 0.5221969887750254, 0.6857930507226663, 0.7165175356894178, 0.29710057972230974, 0.7653554584145255, 0.5181266180283449, 0.9263666890236687, 0.6760673876389692, 0.8037979022896844, 0.027473811082467936, 0.9960811366105884, 0.9944092843088967, 0.0874040890055564, 0.939539739265763, 0.48707681737496256, 0.6622084416157479, 0.787541786006789, 0.9232240415098083},
         {0.23628657682027343,  0.8634662749696801,  0.32625393873447783, 0.0620948174603726,  0.521769030413559,    0.09135578381856102, 0.5113047979380391,  0.939572095680935,    0.7640010915270445,   0.28035298767853334,  0.3537753248451696,  0.7184663809258537,   0.1837831514713517,  0.3109125578917229,   0.716187970778418,    0.5808698753103337,   0.7995997731350332,   0.16332956272477983, 0.041679404344924786, 0.16099886849033573, 0.6404431091652897,  0.27965588434220967, 0.5485291210860236,  0.15143823685005442,  0.07452020131650583, 0.7560159580940693,  0.4393908657580975,   0.09233955391049042,   0.7099292320857081,   0.8323937857855745,  0.870862754050905,   0.46347664450445014, 0.41030402577392366, 0.7729388688270435,  0.6565714498774806,  0.5906638166008455,   0.5865904250434298,  0.6370661173553165,  0.9357339184490244,   0.5508930581497212,  0.07553136408667105, 0.6301006393168922,  0.32920068065527097, 0.21464895029603637, 0.5961026946304954,  0.6919454750326103,  0.42627214891669263, 0.7992106743217215, 0.9870548046349241, 0.7332263443310337, 0.7981197887694207, 0.8233527645936448, 0.17187992933054852, 0.46059456501808294, 0.11743217284791407, 0.1517074418061961, 0.07193870563249194, 0.04634541198253683, 0.37894551448104075, 0.8961531039401187, 0.4941434987912815, 0.9922360739577706, 0.6618071688727001, 0.3019448284338738, 0.35651057281051823, 0.41336383777664654, 0.3522595562518144, 0.3879048444812254, 0.48305673395716, 0.6251914560897138, 0.2539211424600808, 0.03284188727445436, 0.5989303036414264, 0.35528360882719245, 0.5529802995830236, 0.4044702921738549, 0.08733063660799456, 0.12104474417855271, 0.176906496176515, 0.11245115098597847, 0.5316838049735133, 0.31572503719095224, 0.6878228980189534, 0.23377938611843607, 0.05970699176028793, 0.3271878375574816, 0.485473099373108, 0.4065922460514282, 0.030407241352149228, 0.5774088523827484},
         {0.7597539160931781,   0.5175759806860677,  0.6607252091251828,  0.7154032027815705,  0.3290752105038196,   0.11849977801078626, 0.7754479515114169,  0.32225384887689823,  0.22834692653546396,  0.5990063794316293,   0.9821790745305198,  0.3941406264763292,   0.6691822364731059,  0.3156416997953688,   0.22256867029175342,  0.5577465586781848,   0.7849451895614041,   0.33120635711407187, 0.8316696704456051,   0.4421438441268125,  0.39455988338085346, 0.1538640660721481,  0.9492007730924633,  0.8822391247475803,   0.8715377097049734,  0.8820431035854741,  0.36966086258303543,  0.6610837514463657,    0.0884677650194362,   0.45901906370771295, 0.6926533514780218,  0.3118317038048559,  0.32225504388527715, 0.3201680650997413,  0.9404433062423747,  0.09485401461973042,  0.9516798074239158,  0.5762318859834585,  0.6466839339045816,   0.6414955072380865,  0.75639074638575,    0.01753713915427646, 0.7884135109310603,  0.9131856743009001,  0.635233478577313,   0.6469632438141025,  0.8328373696129623, 0.06309287569740862, 0.6018551299108841, 0.15355439958117711, 0.6010740882906898, 0.507236716122638, 0.9868145913539048, 0.7240233572726047, 0.6129589206225308, 0.012950607861749175, 0.8779674593667375, 0.855995547230965, 0.07016132698329192, 0.8948130759381758, 0.9646832990205398, 0.3846940344090699, 0.6592880277181894, 0.47164258877859466, 0.11649247521934458, 0.7638675237357233, 0.9123066144465058, 0.7828773133223281, 0.22304802392834777, 0.7521147030184534, 0.9485389220247517, 0.18863840765209705, 0.04982817519056082, 0.04736025272665034, 0.040637752314722664, 0.8850008776601574, 0.12279328889212304, 0.0850890693998756, 0.5963741084766642, 0.5544737199069429, 0.9452504456716598, 0.17004705775161488, 0.8287264097436339, 0.3414167889462897, 0.1714679460205989, 0.3464682772129425, 0.5986773770650946, 0.09309894654573225, 0.7141211661404115, 0.9284897734217835}
        };


static double get_hash_code_of_id(int id, int x, int y) {
    int a = id < 0 ? id + 7 : id + 6;
    return hash_code[a][x * 9 + y];
}

#endif //VLIANG_CHINESE_CHESS_ZOBRIST_CODE_H
