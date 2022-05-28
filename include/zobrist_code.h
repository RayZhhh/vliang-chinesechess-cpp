//
// Created by 张睿 on 2022/5/20.
//

#ifndef VLIANG_CHINESE_CHESS_ZOBRIST_CODE_H
#define VLIANG_CHINESE_CHESS_ZOBRIST_CODE_H

const static int hash_code[14][90] = {
        {7755333, 7629732, 5999345, 5436017, 8541456, 8470596, 9949807, 4888288, 1048942, 5030713, 4303699, 9333092, 7003934, 7602331, 8577556, 7473848, 3956824, 6978234, 9327013, 3295001, 1174440, 6519554, 5230693, 3982317, 1621076, 978385,  3738536, 7115851, 5581653, 1576246, 9549794, 3887586, 44723,   1107006, 8281574, 5144588, 8090035, 1162966, 8347038, 6169851, 4214786, 5975360, 283066,  4286829, 4784667, 3815649, 5550403, 609981,  7610235, 7421505, 6174985, 3562484, 1026141, 9491519, 2507372, 7143595, 790138,  7935198, 8847908, 1351975, 2620805, 8269925, 5718429, 5657621, 9257327, 7324122, 3157041, 8963858, 3551670, 3235921, 1570700, 1112197, 3292888, 1629266, 5401029, 1656684, 9215313, 6804391, 142006,  1370683, 4956786, 9797256, 5093854, 747882,  6610058, 2242546, 2645684, 7620623, 9949947, 6117464},
        {9850134, 2942497, 5420777, 4648593, 9586447, 9768464, 4533096, 8931694, 6704144, 5514591, 6445600, 8144393, 9197637, 1690837, 197672,  8624264, 5682859, 8474113, 6309863, 8539924, 8230144, 3725222, 1284133, 400303,  3953343, 7352056, 9912594, 3227357, 9663333, 2282804, 3242958, 9860057, 1364787, 2736717, 4550862, 2562555, 4408280, 8966333, 1733664, 1877038, 705513,  5193863, 2167291, 9491817, 6573623, 4075802, 5257147, 5787816, 8495264, 6703621, 8666056, 6681671, 4364356, 1884756, 6516662, 2401262, 4633072, 2246910, 1742670, 2909530, 1183867, 7570042, 202750,  835073,  1721041, 7674213, 1172888, 2973027, 4009532, 8177814, 7397433, 5687372, 7384338, 2489516, 8006014, 7875840, 8612184, 2508607, 9292980, 7551207, 5407718, 8682221, 1607954, 4547814, 3689771, 7304287, 5420560, 2379752, 4008883, 9239840},
        {5999304, 6857204, 8485503, 9619699, 4084099, 7710041, 2069003, 2474293, 9433799, 2172836, 960812,  7761814, 5194648, 6253020, 6640697, 794615,  3662426, 234020,  6093435, 5679199, 8200576, 9857758, 7553790, 5058883, 1828527, 3586000, 6370935, 8184612, 308898,  9357603, 7439170, 8138190, 6439187, 1338781, 9049957, 6893544, 2693059, 8306122, 7991037, 3825453, 1358232, 507123,  7251559, 9261509, 4882476, 1110614, 5787881, 9721894, 4266147, 1689530, 4462903, 5602910, 29157,   8571022, 3492472, 5233988, 8532226, 8344041, 4515637, 1474279, 6246708, 6332051, 4751206, 8313701, 5944261, 1418633, 1611273, 5304711, 1717039, 4256314, 3613095, 7074824, 4241095, 3594046, 7463872, 3656303, 3760083, 7226299, 1788728, 4918217, 5893336, 9896863, 5130354, 8997412, 4561840, 382991,  9569507, 298783,  7077559, 3940619},
        {1598741, 7371536, 8756062, 4308950, 8727473, 4766970, 8289298, 1552798, 3704649, 5844649, 554882,  8163654, 8216041, 5417629, 540146,  6045488, 4446336, 2113781, 623713,  1278934, 5991946, 379025,  3584273, 1887532, 9268625, 1159669, 5395712, 6222299, 2778715, 8474831, 5119678, 6035989, 4386012, 6326288, 4021146, 8835967, 6091988, 6691899, 2409480, 8684693, 1715268, 4710076, 646943,  3259421, 5346986, 1586637, 268571,  7687751, 7487852, 9241657, 2221767, 2443298, 1368443, 3262794, 1860935, 3415778, 4112451, 2342891, 4521914, 7162422, 6123326, 3053467, 1252947, 3302681, 7357943, 8542050, 1593343, 9035790, 996634,  8540147, 9167972, 7840806, 3427121, 5929931, 6305164, 5561339, 4430608, 2041612, 5887560, 2282268, 2991464, 8839731, 2209880, 7673290, 2247656, 1205483, 7744571, 804268,  1757289, 6633487},
        {9405713, 2829883, 6477302, 2835249, 6153528, 2396203, 9633586, 5977897, 9596310, 9139331, 1007482, 3585588, 623505,  226407,  3071841, 6492329, 8043158, 8531784, 4880487, 3658770, 9698888, 8746301, 7648187, 2151842, 2605998, 9485134, 6553878, 2134990, 6273289, 5289798, 458154,  3328015, 2566583, 2312458, 4946672, 5069414, 6221953, 5425747, 4394376, 6850419, 2431054, 2518927, 5591129, 9988759, 1797953, 3821249, 8877530, 3971514, 8406281, 235980,  2710431, 2920229, 3737491, 4873646, 4110836, 8617821, 7745460, 6240581, 542585,  6585608, 8519623, 9869003, 8428439, 810142,  3658285, 7567374, 9730853, 893327,  9725708, 9924889, 807966,  2635674, 981012,  8221546, 7101015, 9361319, 4943910, 6475270, 3117581, 6654810, 301716,  3000209, 9645800, 7603466, 2164048, 3555334, 9167854, 9125442, 736071,  4930114},
        {6036769, 2512472, 2108119, 8644053, 138749,  2927588, 4048942, 9329515, 1483982, 3271938, 5441805, 1322293, 8452047, 7571143, 5317128, 1985,    4263760, 7830494, 6312267, 1504298, 4659516, 6169576, 7828547, 5570007, 4734841, 970767,  6157551, 1500338, 4417141, 1762379, 2413183, 6456149, 163258,  2606015, 4232912, 8668356, 5115726, 7869088, 3901117, 5519625, 1176247, 7437231, 3799366, 7912415, 4238181, 657679,  9902933, 7856079, 8165489, 9603538, 5419795, 5785752, 4013805, 2610157, 9607836, 7768377, 8460011, 8458680, 1307893, 456273,  9439878, 68154,   2794775, 3416239, 7589053, 4106423, 7175300, 4292270, 9240878, 9541340, 1751894, 2152511, 455207,  3827682, 522197,  8326204, 1835629, 161464,  1299621, 2053901, 738156,  3032182, 6816717, 354348,  882700,  2164843, 4612707, 7653983, 9349307, 6867470},
        {7508440, 930099,  7474360, 3786097, 5036526, 386278,  5257649, 1118086, 6321326, 4008793, 8549406, 1445958, 6592953, 6745246, 4507129, 3527709, 2771368, 1501809, 3595177, 615960,  8371128, 9672966, 5745881, 9177088, 4354290, 3497797, 4209062, 7242813, 498418,  1179355, 3087595, 6050571, 1348609, 8408827, 3589824, 2115290, 1886899, 6703703, 9625367, 9424051, 679357,  9799277, 5529037, 3056429, 2450652, 4225372, 7418309, 6207126, 7787789, 9155277, 4972966, 2323863, 4989211, 3631434, 2271268, 2872301, 7952383, 6352515, 4725186, 9101096, 4432444, 4349096, 4127936, 3104040, 1006450, 2080218, 5360272, 9462530, 4642213, 1750696, 6397681, 3800476, 5897658, 8979125, 7918845, 8695061, 5466101, 5339101, 36405,   560594,  4034792, 751260,  1454319, 3359055, 5238523, 4221311, 701743,  6289705, 2867053, 999321},
        {1634,    2971521, 6424550, 7878084, 9802916, 9056009, 3641220, 6053491, 6038304, 3694275, 4601728, 2737391, 2765547, 7831083, 9781973, 8543499, 8083,    8909939, 3475241, 7559525, 331763,  7247080, 4840705, 973719,  7977570, 4068560, 1121697, 3141657, 1215874, 5003472, 1458125, 1059141, 1996058, 5687668, 5156873, 4349669, 6935972, 8056137, 5285963, 3080022, 228944,  6888599, 7022716, 4985072, 2141731, 6221609, 313101,  2013018, 6435011, 4351880, 8088924, 8494810, 6258745, 4329302, 4541434, 9696621, 857891,  4074491, 2764418, 31784,   4769705, 6554521, 7456770, 4788714, 7102033, 5811825, 6314001, 7873887, 952723,  9065069, 3240090, 774049,  2063471, 8587148, 7575544, 4709381, 1397133, 9614264, 6164479, 8779462, 8485725, 2151382, 9272992, 1796405, 1117057, 5213190, 7123038, 4454648, 2211122, 1776013},
        {1120503, 1504462, 6583078, 1514965, 2733081, 676291,  8697881, 6261940, 3413046, 6245653, 7492296, 43880,   961953,  333373,  5873243, 1547089, 1298751, 4303517, 597121,  1902180, 9719755, 5951481, 2892981, 4795580, 2428349, 5567245, 1413080, 9087331, 7364307, 5413901, 6877597, 6351284, 3176982, 2679121, 2125967, 7052567, 6563655, 5537340, 2195502, 9438573, 1133727, 5602970, 6518655, 4643536, 5461426, 7760066, 9363525, 9993065, 4054127, 121442,  5237859, 43864,   2590365, 2700289, 3135031, 1505196, 7971047, 3269951, 7221193, 3862431, 4479344, 2842596, 1845973, 2259420, 9659172, 1215057, 5604806, 2995192, 7399166, 5110252, 2589202, 4851849, 1148447, 7585128, 8931928, 1394344, 7192483, 7581169, 9287324, 369148,  6481786, 2761085, 982629,  6377655, 3633118, 7105374, 3234440, 2111497, 3412360, 7135036},
        {5045105, 1610762, 8260137, 7081775, 8177058, 6242440, 5235758, 3844630, 948810,  395264,  7131950, 7152038, 4504517, 9248414, 452368,  8990913, 5679737, 5395404, 2445775, 9069398, 9619209, 4590793, 455252,  9847539, 898164,  3436171, 9467769, 5500200, 4056924, 3433245, 7938859, 4069107, 3179183, 6505616, 7719145, 1016003, 5427641, 6827221, 1223870, 5406470, 5296313, 2594213, 7863576, 7034038, 4747049, 9238382, 2193496, 3936805, 9368526, 2504064, 8241209, 4963845, 2229142, 5796789, 8036532, 1316272, 5190978, 1260769, 7494597, 4317907, 2110175, 8153649, 9492500, 4063067, 9569777, 5260759, 2231869, 5044077, 8574316, 6327453, 794162,  378681,  4981087, 8786932, 1172428, 5837619, 7351285, 6422297, 9002750, 8515181, 8374884, 6025373, 9720525, 2690684, 56307,   6601215, 2931194, 7196325, 3443687, 7215993},
        {1411986, 4437017, 842686,  6197321, 4350689, 1100321, 2176553, 69886,   5179432, 4549722, 7437315, 5345590, 6675887, 6912043, 4018677, 86231,   9881282, 949883,  1129433, 5018078, 8824047, 7952523, 3456883, 5901533, 39876,   8083871, 2782940, 9845389, 4443448, 7893517, 9351344, 8304029, 9234000, 8027137, 4442583, 8607227, 9206373, 6564976, 1833817, 4046070, 91160,   9872301, 8604332, 9774807, 1361979, 3363216, 5092725, 8087286, 2324887, 9159367, 9720245, 1987975, 3244380, 6267617, 6865397, 401352,  2762404, 1605850, 5008152, 1849828, 3931223, 6973649, 7957765, 5979159, 3807963, 7894659, 4136452, 3921642, 5748107, 5150046, 7611843, 9161219, 9287157, 8777515, 9854352, 300945,  9814131, 7327939, 3041301, 5932097, 9117537, 2251746, 4137846, 9665526, 8323890, 8429755, 3955434, 309699,  6750821, 7068254},
        {6921760, 8166191, 3761242, 6445702, 5391854, 3462212, 5832037, 9328468, 6988167, 7051100, 7740142, 3265656, 4678206, 6685525, 5020886, 1428105, 7081482, 4404475, 4667870, 7174241, 843229,  1873937, 2420655, 5105540, 7820564, 882503,  7925953, 5016942, 7297464, 5616957, 3559983, 2852609, 7478116, 1829243, 8764106, 4545049, 1103936, 5555019, 9372800, 4445642, 7197716, 655352,  602495,  9947242, 4659104, 126923,  3121743, 7854557, 3718777, 862441,  3937636, 6075635, 8104415, 5341807, 7710368, 6287812, 4179759, 6595870, 9547248, 9374098, 3288748, 4708472, 7329471, 5631037, 69935,   4108800, 189367,  6016650, 2602082, 954865,  9882823, 9037156, 9900034, 9020315, 3491031, 263756,  8500691, 670538,  9137638, 7925805, 2662067, 6750420, 1221864, 8544331, 2044177, 5504890, 8045088, 1149873, 6648646, 6014735},
        {2647846, 7271260, 1264663, 6054013, 7176171, 6586960, 702120,  7761685, 2160608, 4898259, 2688438, 7068944, 4718251, 1913584, 7463827, 4435025, 3877542, 1225870, 1830401, 5118141, 6977573, 3819934, 693786,  6944472, 8408056, 9464428, 981573,  2337001, 833084,  7422986, 1231128, 9227303, 9481279, 9061785, 5110033, 2397218, 2086846, 135800,  8665593, 2783685, 630522,  9803626, 9195555, 7328807, 6156376, 6750804, 8290402, 6068593, 4629821, 194179,  2818279, 6327604, 54222,   4994882, 5406802, 6123094, 877865,  5625128, 321725,  181046,  7100070, 3314070, 1550621, 2327828, 8424624, 4340554, 7370457, 7445053, 8310719, 5145686, 9711124, 4661495, 4835990, 1705702, 7222711, 1004823, 6913222, 6435700, 8112492, 1347157, 3591747, 5787400, 2538309, 6152349, 4926502, 5659143, 4628242, 3269173, 5212168, 9753931},
        {1042153, 3813466, 3256771, 8101399, 6398887, 5043571, 9808576, 9102174, 5863635, 5057261, 9252052, 8658157, 1723155, 5124681, 1253157, 4219839, 3872248, 5520626, 8161117, 9911864, 3793090, 9830835, 5663355, 1290583, 7829741, 880804,  7442160, 4742473, 8343324, 8671938, 9396148, 7049842, 679101,  7008702, 5366514, 5230310, 9784855, 861744,  4247532, 5399185, 2790699, 935817,  7862720, 2108860, 2893635, 5397627, 52512,   6386996, 5485893, 1267570, 46275,   1525302, 9624272, 9590676, 7380920, 563305,  6658419, 9175854, 1380346, 8366591, 3119179, 3428916, 5524370, 4216573, 6813861, 3603635, 5912794, 7908903, 3483455, 9656471, 3469666, 3500256, 6347537, 6814383, 1534792, 48259,   2395838, 1951488, 4053966, 7956940, 7381089, 8919181, 4706371, 2870135, 6126028, 6085616, 3997034, 6447880, 5978110, 2514299}
};


const static int verify_code[14][90] = {
        {8758129, 7249344, 756459,  1872744, 7008760, 3900476, 5040686, 4965429, 5584047, 4438219, 857295,  4500503, 8599139, 3218304, 9567379, 3360650, 4744753, 6362627, 5832515, 9014645, 9551566, 3228020, 3757589, 1043717, 5014229, 1285446, 1816757, 5685664, 1533814, 9614998, 8909014, 810113,  8866009, 2716233, 774648,  2638712, 7303389, 8140009, 701097,  3736919, 7673616, 8567113, 956514,  329460,  8901432, 1390644, 1711586, 5829400, 4860822, 6603229, 2344940, 6621174, 8034736, 6846804, 5974729, 5600821, 6103303, 1851812, 1818738, 8752033, 8997427, 3174357, 1557654, 124546,  8183247, 4133925, 5260874, 981777,  6983886, 4160996, 9631499, 9597498, 598481,  6382955, 6336946, 9206742, 7144475, 2208378, 1013854, 2954024, 6527675, 6913912, 4170735, 6332330, 2235606, 5794593, 3659085, 9569249, 2253183, 1307592},
        {4643434, 4691996, 9215756, 7821039, 7073090, 4590960, 6643102, 2073672, 2543079, 4301810, 7638942, 4257755, 2129061, 7939098, 4794079, 6756798, 4290774, 8239641, 5197268, 5001282, 7260803, 9511916, 2436463, 7649732, 3470257, 8938045, 8264064, 1359104, 4510188, 5637858, 203341,  8777613, 3887371, 1679913, 7789206, 7074749, 1405291, 4312236, 9365027, 8317399, 7386008, 4085937, 3398177, 2307590, 7145775, 9257754, 3130572, 7116555, 6147086, 2882959, 1046407, 2481430, 4072098, 5347951, 117853,  6475046, 1697113, 1742268, 2080497, 6415921, 7895089, 432615,  9093795, 854692,  5352920, 6476910, 4057848, 654875,  2662465, 1104247, 6586312, 3679965, 7329105, 6387057, 6176284, 9405555, 8938846, 2444620, 1469500, 6894270, 4234762, 3042525, 4665219, 2002967, 6175840, 4290502, 3123668, 7435782, 7186054, 291480},
        {5989939, 2313258, 2748747, 9057614, 2271759, 6296911, 5261195, 1784397, 8220551, 6990257, 9636455, 8661872, 6093724, 8331433, 1524400, 4802358, 3417169, 1999220, 6221086, 576983,  1720408, 3473376, 1345369, 1678713, 6382904, 9321866, 9183959, 5567456, 4708528, 2531704, 5240862, 2603204, 7636205, 8256734, 7974420, 2136091, 1598278, 3224876, 964936,  6097588, 954129,  8228947, 2828123, 5225008, 8155146, 4619332, 2074400, 5951832, 8338093, 2523439, 3811300, 9209281, 7397499, 635967,  2696047, 5909952, 7753677, 4855703, 1867600, 7722227, 4011491, 5788672, 722242,  5894530, 1496035, 3194127, 5344059, 5351438, 4254867, 8818985, 4161408, 6059009, 5532482, 7747980, 7972748, 8744592, 2951220, 2390923, 7869980, 7456793, 2673808, 2535110, 6784678, 7164117, 1676265, 9510062, 392404,  616246,  4925904, 2443413},
        {932520,  5029776, 4737692, 9830916, 3135715, 5810623, 2873232, 200148,  4898695, 1488225, 2050157, 1516692, 6605283, 1312019, 2445732, 163139,  2065410, 4548611, 506986,  6815467, 928276,  8418388, 1920705, 8347946, 7123190, 9823276, 7950134, 2016867, 391402,  4542689, 4511250, 605065,  8294472, 6412622, 6339986, 4953294, 4219501, 8153242, 4392805, 3361204, 2848830, 4973205, 3226533, 5709774, 8321538, 1854327, 6519368, 3838715, 1886385, 5508121, 3123523, 8706490, 5230571, 2396115, 3080947, 9167239, 2865970, 4918740, 2887108, 6818049, 1964254, 8902980, 1953813, 6301620, 854600,  6856861, 7700586, 693564,  8032419, 3109255, 4995109, 7160163, 1974828, 8916341, 6766774, 8941599, 8318340, 7891500, 6533385, 5897283, 5026532, 4703261, 309590,  7344045, 8060191, 2886340, 4906615, 7724625, 9759710, 823702},
        {1986403, 7762990, 9659306, 8482937, 2399269, 1194701, 2774829, 1328180, 3312708, 9904645, 3541773, 1979153, 1429986, 8361119, 4527308, 4651812, 9200693, 1604386, 7799941, 2190487, 7341423, 9729455, 3412688, 589269,  6213266, 5796984, 3840388, 1300812, 643846,  3412848, 5409052, 7343584, 7635091, 4836063, 7764935, 5244015, 4064010, 406357,  253253,  1187873, 1962205, 5326883, 9711241, 6405571, 2250902, 394160,  7627531, 3779037, 3911781, 9136476, 5879565, 4933130, 4489910, 5003658, 9333055, 4662500, 9553593, 8745216, 472240,  7445177, 3276974, 7920531, 5926975, 9007052, 9664740, 7603892, 7272438, 4426824, 4104284, 3778828, 8799530, 3108856, 7909214, 8660321, 3088770, 101796,  4309094, 240132,  1167794, 2703683, 2943845, 6719592, 7792302, 1069680, 1337203, 175889,  3962592, 1626437, 6052210, 2801981},
        {8172536, 2497494, 3272671, 3366936, 5085188, 857031,  8408055, 1162620, 5338919, 3154637, 6985340, 9634313, 3010269, 491684,  4569792, 2136960, 7894462, 3080288, 1747707, 7815406, 8211815, 9678686, 1307647, 6476112, 5607997, 172315,  8672725, 7499488, 8388405, 2057709, 3365004, 9336109, 811664,  4486752, 8824088, 2936732, 5964521, 6741721, 255518,  4585173, 7250185, 1536912, 5350563, 1034735, 8844421, 7380566, 697560,  2593026, 8608469, 8381194, 7495932, 7856640, 7895133, 4345264, 3787549, 7166327, 1444138, 8788653, 6836111, 534901,  7135140, 7572107, 8513740, 9794287, 9751511, 6271386, 8594996, 4014760, 5105315, 105613,  5712030, 1868526, 883632,  6272807, 3390620, 4541503, 8398672, 4879381, 9065342, 8041235, 5058881, 1300864, 7263153, 4305551, 825488,  9773934, 4248151, 6385714, 3178752, 5295267},
        {336342,  4159444, 4190369, 8490602, 7817710, 3523329, 183343,  6017789, 6963925, 3820800, 9157811, 7280503, 9953550, 5380970, 3671137, 6754692, 2712595, 1475283, 7182831, 67690,   7646806, 6743061, 9615,    1120366, 6033082, 7193673, 6983221, 7005526, 7440931, 5262195, 2663291, 7251206, 4970893, 7077073, 1529986, 4005354, 9325367, 8092434, 9965704, 178832,  1768304, 7544335, 4032543, 3276510, 5883736, 1809376, 2061951, 3671670, 709136,  1675760, 3895223, 7416758, 3298103, 8781000, 9248311, 5334001, 7057902, 2027129, 6121656, 2092202, 3310887, 5653405, 6435525, 1251504, 7444867, 6828144, 143594,  4845735, 7745972, 2115460, 962299,  8972377, 4548605, 8979318, 6550727, 73090,   9690586, 606461,  3485587, 113087,  1427589, 9761404, 2698076, 2705567, 7939511, 130834,  4174218, 6377822, 3352408, 1671393},
        {667500,  5638467, 3803178, 9843960, 8932434, 5280700, 7490142, 7299183, 3559896, 8444337, 1881229, 573182,  2879893, 4359794, 3292482, 3658937, 8594654, 7410053, 8903079, 4938056, 814711,  5172051, 8939145, 3889238, 7992917, 9436828, 7237071, 9233899, 6886085, 858145,  1688147, 736058,  1121223, 4842187, 2169764, 2742719, 8203093, 3566349, 2484503, 8732650, 3872087, 6602995, 4556930, 2635563, 9606196, 524476,  7678909, 4490380, 3758077, 6078576, 2947816, 5130366, 9328033, 48948,   3207974, 7014600, 1695956, 7753000, 1784234, 6069352, 7770055, 1280067, 9087558, 2459599, 3957460, 8035606, 4776044, 6580054, 4121569, 3932546, 4570793, 236705,  263245,  5658800, 5054590, 1984018, 8047753, 6850354, 6822326, 9889600, 6496603, 3712221, 6205656, 4617242, 6173198, 6654955, 8460372, 650913,  3013484, 5852308},
        {783494,  3726431, 5587551, 275983,  1818114, 8094140, 2025391, 1726358, 5407501, 8105110, 9099809, 7653431, 276045,  4794972, 31717,   9150112, 4043096, 9633677, 9467839, 3400414, 9516775, 4416085, 3778088, 3077950, 3568366, 8387443, 2329677, 8715559, 4053897, 1129447, 717258,  3904754, 8228037, 2476726, 63170,   7334098, 6886462, 8790220, 7449139, 138487,  2076342, 8283075, 1300528, 1806713, 2630629, 6776309, 2116517, 2982578, 1010340, 9255656, 3324346, 8895211, 6980041, 1907617, 9233020, 2867142, 8495251, 3931901, 7071655, 5374069, 7846512, 8359085, 7919892, 468134,  1583372, 6346444, 6972573, 8026947, 6032562, 9981560, 7028158, 7253460, 6328134, 4492443, 350105,  4127184, 5787385, 1944567, 3122712, 3095148, 4194862, 4999318, 3607675, 1191385, 8097796, 1115043, 9804914, 986606,  3569803, 4690989},
        {4930925, 7295135, 2065725, 7086090, 9350252, 1404055, 2968982, 2188671, 5730374, 5739906, 2223831, 8269823, 137623,  1351181, 5048452, 5222283, 5551471, 360228,  2140774, 9968362, 5846810, 5626090, 3017493, 1814540, 7678627, 260180,  7167735, 3837038, 4900703, 349597,  3556336, 6001787, 5159777, 5268260, 1677731, 653870,  1128841, 1293948, 2839955, 1255642, 9478032, 5899712, 8649280, 809386,  9128822, 2051011, 4769511, 7269501, 6596996, 4115348, 1946008, 9430837, 302159,  9579004, 3012993, 8273979, 7606293, 3665953, 4143723, 5554871, 8041129, 7166833, 956631,  3545344, 3693888, 1311320, 5256547, 7262745, 3043195, 7355090, 6168632, 3271002, 7671744, 2702974, 213658,  7192104, 2229547, 9852781, 8476815, 5436106, 6781386, 9219670, 5438199, 5339427, 7244329, 1988842, 3261692, 1895338, 4005944, 4544697},
        {7379927, 8567173, 1011129, 1737511, 4066573, 4293948, 7615214, 2274075, 8353163, 8729710, 3323269, 5856609, 1126244, 3002079, 1170328, 8344695, 7531591, 3832073, 8944479, 8177806, 4915792, 4726479, 8714571, 4571469, 7451494, 9135629, 4196508, 5587919, 6321131, 6963632, 2376922, 2082550, 8874966, 7624698, 510231,  1740322, 7532793, 9958387, 2114879, 5941688, 9364671, 1748202, 5916830, 1035511, 264552,  9332139, 9823123, 4746780, 3421721, 850398,  7955590, 7909904, 398438,  5044635, 2534593, 1493675, 4538220, 1204763, 3974890, 8971930, 657704,  4853450, 1940534, 4494316, 2016042, 8065092, 7302943, 8024463, 5409310, 2935218, 9956069, 9638242, 7903413, 1647866, 264848,  6512685, 4197491, 6832662, 2557873, 7786557, 1900850, 1459957, 7522522, 4436411, 3109953, 8391489, 6620501, 3587398, 4588019, 5885740},
        {5714068, 9265966, 5578294, 6851225, 6977936, 4501976, 1823089, 6447659, 7869141, 2900661, 6714171, 4754035, 3436918, 1330248, 5666121, 8654319, 3576884, 9208928, 7782806, 9835602, 9968622, 4025292, 9678077, 3850169, 8382985, 7189194, 9915389, 8562126, 805239,  9085436, 8946996, 8980826, 8392422, 7290532, 8661922, 9477499, 668029,  7313207, 7692911, 3688123, 8554465, 932180,  3486087, 7024725, 8853401, 3230169, 9803056, 6648920, 5606485, 5760956, 8803698, 9005652, 9403600, 9936703, 148943,  5571757, 9153142, 1685669, 5666283, 3343059, 2088537, 5705794, 7036853, 7765410, 6857509, 5227558, 5691377, 2309185, 1425347, 1099898, 8643318, 693398,  2220703, 2225840, 1341084, 4884747, 3462226, 7899934, 8787147, 4428528, 5926570, 1437417, 9150461, 412515,  2553118, 3635475, 9889567, 421517,  4228006, 4069816},
        {5007302, 9209502, 2849801, 8005199, 3474033, 3497767, 351460,  6786418, 3084866, 8301837, 1737949, 9976661, 1057273, 6496351, 7396187, 8223036, 2529130, 2946385, 4943722, 6854448, 783135,  9465276, 3704824, 1554914, 8502122, 7103162, 5537456, 9105779, 7650790, 7827080, 4181827, 8153196, 6682882, 8522630, 1561006, 7232617, 7688860, 6428826, 3536361, 9869943, 2827648, 6611915, 9505309, 9479353, 8927031, 8890569, 9926182, 9990748, 1490790, 3744022, 3364730, 1665114, 4516713, 4166331, 9979085, 5394013, 508084,  3174104, 1494754, 2929784, 5852314, 4731677, 8668481, 4955963, 343871,  9226849, 5999584, 3682768, 6044679, 3311935, 19652,   1740441, 9903681, 7919046, 1876208, 4543585, 6598276, 7565123, 7123275, 9012558, 2913855, 8681403, 5641497, 7563347, 2643665, 4633661, 2432742, 2615264, 1469765, 343656},
        {5668905, 3516176, 4576842, 9978912, 1821864, 4747883, 5854167, 7047058, 8961317, 1549638, 6456999, 7412623, 8379513, 6685706, 2227255, 2248297, 1586620, 9983245, 4014266, 9739334, 4417768, 479671,  2289987, 1478899, 2502561, 9544087, 7619006, 1923801, 2670115, 2175213, 1522242, 7024199, 2997441, 2828670, 8064222, 1197516, 156281,  1589350, 5097358, 185919,  6473224, 6280001, 5512630, 1018373, 690257,  6185042, 3074639, 9292433, 5797610, 3469006, 4459972, 8297541, 4508067, 9081921, 8971363, 4120776, 7951647, 969318,  66128,   5807619, 5991853, 3742422, 8315885, 9894451, 8199428, 614528,  3705583, 4186125, 2966837, 372397,  6283366, 6521116, 8506456, 4426930, 8088825, 448381,  3547717, 1575270, 6015718, 1234189, 7433218, 1006846, 4806218, 2423864, 9011073, 7298797, 1727310, 5302457, 1230554, 4671581}
};


static int get_hash_code_of_id(int id, int x, int y) {
    int a = id < 0 ? id + 7 : id + 6;
    return hash_code[a][x * 9 + y];
}


static int get_verify_code_of_id(int id, int x, int y) {
    int a = id < 0 ? id + 7 : id + 6;
    return verify_code[a][x * 9 + y];
}


#endif //VLIANG_CHINESE_CHESS_ZOBRIST_CODE_H
