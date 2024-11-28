#include <iostream>

#include <Node.hpp>
#include <Asset.hpp>
#include <Player.hpp>
#include <Monster.hpp>
#include <AdventureGameMap.hpp>

using namespace std;
using namespace chants;

bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

void AtNode(Node &viewPort)
{
    cout << "\033[2J\033[1;1H"; // clear screen

    // Output contents of this Node
    cout << "Location: " << viewPort.GetName() + "\n\n";
    cout << viewPort.Description << endl
         << "There are paths here ..." << endl;
    for (Node *node : viewPort.GetConnections())
    {
        cout << node->GetId() << " " << node->GetName() << endl;
    }

    // Show all assets in Node
    for (Asset *asset : viewPort.GetAssets())
    {
        cout << "Asset at this node: " << asset->GetName() << " " << asset->GetMessage() << " " << asset->GetValue() << endl;
    }

    // Show any monsters at this Node
    for (Monster *monster : viewPort.GetMonsters())
    {
        cout << "Monster at this node: " << monster->GetName() << " " << monster->GetHealth() << endl;
    }

    cout << "\n";
}

int FindNode(string loc, vector<Node> *gameMap)
{
    int intLoc = -1;
    if (isNumber(loc))
    {
        intLoc = stoi(loc);
    }
    for (Node node : *gameMap)
    {
        if (node.GetName() == loc || node.GetId() == intLoc)
            return node.GetId();
    }
    return -1;
}

int Battle(Player player, Monster monster)
{
    srand(time(nullptr));

    return player.GetHealth();
}

std::string getLastWord(const std::string &str)
{
    // Trim trailing spaces
    std::string trimmed = str;
    trimmed.erase(trimmed.find_last_not_of(' ') + 1);

    // Find the position of the last space
    size_t pos = trimmed.find_last_of(' ');

    // Extract the last word
    if (pos == std::string::npos)
    {
        return trimmed; // No spaces found, return the whole string
    }
    else
    {
        return trimmed.substr(pos + 1);
    }
}

//
// All this game setup will be moved to gamemap and out of the main function
//
int main()
{
    // AdventureGameMap _gameMap;

    vector<Node> gameMap;

    // build all nodes
    Node home(0, "Home");
    home.Description = "You are standing on the front porch of a warm and comfortable home that exudes charm and\ntranquility, inviting visitors to feel welcome even before they step inside.\n";

    Node mountain(1, "Mountain");
    mountain.Description = "A majestic mountain rises grandly from the landscape, its towering\npeak piercing the sky and exuding a sense of awe and reverence.\n";

    Node city(2, "City");
    city.Description = "A typical city is a bustling hub of activity, blending diverse elements of\narchitecture, culture, and human interaction. It features a variety of neighborhoods,\neach with its own character, from high-rise apartment buildings and business\ndistricts to residential areas and parks.\n";

    Node ocean(3, "Ocean");
    ocean.Description = "The sea appears restless and chaotic, with surging swells that seem to roil\nand churn, as if the ocean itself is furious, thrashing in a wild, unpredictable rhythm.\n";

    Node island(4, "Island");
    island.Description = "In the midst of an angry sea, the island appears as a defiant outpost,\nbattered but unyielding against the surrounding chaos. Jagged cliffs rise abruptly\nfrom the churning waters, their rugged faces streaked with dark, wet stone, dripping\nwith the constant assault of waves.\n";

    Node hut(5, "Hut");
    hut.Description = "A hut stands as a weathered refuge, small and sturdy against the backdrop of\nthe raging sea. Its wooden walls, gray and splintered from years of exposure to\nsalt and wind, are patched together with whatever materials the island could provide—driftwood,\npalm fronds, and rough-hewn stone.\nThe roof is thatched with dried leaves, lashed tightly\nto withstand the powerful gusts that whip across the island.\n";

    Node quicksand(6, "Quick Sand");
    quicksand.Description = "A patch of treacherous quicksand lurks, deceptively blending into the surrounding\nterrain. It lies at the edge of a narrow clearing, where the ground transitions\nfrom rocky soil to a stretch of damp, silty earth.\n";

    Node cave(7, "Cave");
    cave.Description = "Here is a cave nestled into the rocky cliffs that rise above the angry sea, is a cave that\nseems carved by nature's fury over centuries. Its entrance is half-hidden by\nthick vines and jagged boulders, giving it an air of mystery and shelter.\nThe mouth of the cave is wide and low, just tall enough\nfor a person to crouch and enter, and it faces away from\nthe wind, offering some protection from the relentless storm.\nA strange door which resembles your own front door is present in the back.\n";

    Node beach(8, "Beach");
    beach.Description = "A beautiful beach stretches out in a graceful curve, bordered by soft, powdery sand that\ngleams white under the sunlight. Each grain feels fine and smooth beneath bare\nfeet, as though sculpted by the gentle hands of time and tide. The shoreline\nis kissed by the crystal-clear waters of the ocean,\nwhere the surf laps quietly and rhythmically, creating a soft,\nsoothing sound with each wave.\n";

    Node village(9, "Village");
    village.Description = "Nestled within the rugged embrace of the mountain, a quaint village clings to the\nslope, its stone cottages and winding cobblestone paths blending harmoniously\nwith the natural terrain. Smoke rises lazily from chimneys, hinting at warm hearths\ninside, while the sounds of laughter and clinking tools echo faintly in\nthe crisp mountain air.\nNotably, in the center of the village lies a magical portal. When you\npeer within, you see your own home in the reflection.\n";

    Node chasm (10, "Chasm");
    chasm.Description = "A yawning chasm stretches between the cliffs, its depths lost in shadow and mystery.\nSuspended precariously above it is a swaying rope bridge, its weathered planks\ncreaking ominously with each gust of wind. The bridge offers the only path\nacross, connecting to a distant, solitary tower that seems to watch silently\nover the abyss.\n";

    Node tower (11, "Tower");
    tower.Description = "A solitary tower rises high above the surrounding landscape, its weathered stone\nwalls standing proudly against the sky. Its high windows glow faintly with the\nflickering light of candles, casting a warm glow into the night. A spiral staircase\nwinds upward inside, leading to the tower's peak, where ancient secrets may lie,\nwaiting to be uncovered.\n";

    Node meadow (12, "Meadow");
    meadow.Description = "Outside the city's outskirts a serene meadow unfolds like a painter's masterpiece, its vibrant wildflowers\nswaying gently in the breeze. The grass is soft and lush, dotted with daisies\nand clovers, and the air is filled with the melodious song of birds.\nA brook babbles quietly nearby, completing the idyllic scene.\n";

    Node forest (13, "Forest");
    forest.Description = "A dense forest sprawls before you, its towering trees forming a natural canopy that\nfilters the sunlight into golden beams. The air is rich with the earthy scent\nof moss and leaves, and the occasional rustle hints at unseen creatures moving\nthrough the undergrowth.\n";

    Node waterfall (14, "Waterfall");
    waterfall.Description = "A breathtaking waterfall cascades from a cliffside, its clear waters plunging\ninto a crystal pool below. The mist from the torrent creates shimmering rainbows\nin the sunlight, and the sound of rushing water is both invigorating and\nsoothing, echoing through the surrounding forest.\n";

    Node ruins (15, "Ruins");
    ruins.Description = "Deep within the forest, a lone ruined structure stands among the trees, its stone\nwalls weathered by centuries of neglect. Ivy and moss cling to its ancient\nsurfaces, while shattered remnants of once-grand columns lie scattered around.\nThe air is thick with the scent of damp earth and old stone, and the silence is\nbroken only by the rustle of leaves in the wind, as if the ruin itself is whispering\nsecrets of a forgotten past.\n";

    Node swamp (16, "Swamp");
    swamp.Description = "A murky swamp stretches endlessly, with twisted trees clawing at the sky from pools of\nstagnant water. The air is thick and humid, buzzing with the sounds of\ninsects and the occasional croak of unseen frogs. A faint, sour smell lingers\nin the stillness.\n";

    Node graveyard (17, "Graveyard");
    graveyard.Description = "Amid the murky depths of the swamp, a forgotten graveyard lies half-swallowed by\nthick fog and damp earth. Weathered headstones rise like shadowy sentinels, their\ninscriptions barely legible, obscured by moss and vines. The air is heavy with\nthe smell of decay, and the occasional croak of a frog echoes eerily through\nthe stillness, adding to the haunting atmosphere.\n";

    Node volcano (18, "Volcano");
    volcano.Description = "After emerging from the swamp, the terrain shifts to jagged, barren rock. In the distance,\nthe silhouette of a massive volcano looms, its peak hidden behind a veil of mist\nand low-hanging clouds. The air grows heavier, thick with the smell of sulfur\n. Though the volcano appears dormant,\nthere is an unsettling sense that it could awaken at any moment. However, a strange\ncompulsion stirs within you, urging you toward the summit.\n";

    Node castle (19, "Castle");
    castle.Description = "At the summit of the dormant volcano, a towering castle stands in eerie silence,\nits grand stone walls weathered by time but still formidable. The castle's spires\nreach high into the mist, and its imposing structure speaks of a once-great power that now\nlies forgotten. Ivy clings to its walls, and the heavy wooden doors creak in\nthe wind. This is what you have come for, the final destination of your journey,\nwhere ancient secrets and untold mysteries await, hidden within the fortress’s\nlong-forgotten halls.\n";


    // connect nodes paths
    home.AddConnection(&mountain);
    home.AddConnection(&city);

    mountain.AddConnection(&home);
    mountain.AddConnection(&ocean);
    mountain.AddConnection(&city);
    mountain.AddConnection(&village);
    mountain.AddConnection(&chasm);

    ocean.AddConnection(&mountain);
    ocean.AddConnection(&city);
    ocean.AddConnection(&island);

    city.AddConnection(&home);
    city.AddConnection(&mountain);
    city.AddConnection(&ocean);
    city.AddConnection(&meadow);

    island.AddConnection(&ocean);
    island.AddConnection(&cave);
    island.AddConnection(&beach);
    island.AddConnection(&quicksand);
    island.AddConnection(&hut);

    cave.AddConnection(&home); // one way connection
    cave.AddConnection(&beach);
    cave.AddConnection(&island);

    beach.AddConnection(&cave);
    beach.AddConnection(&island);

    hut.AddConnection(&island);
    hut.AddConnection(&quicksand);

    quicksand.AddConnection(&hut);
    quicksand.AddConnection(&island);
    quicksand.AddConnection(&cave); //one way connection

    village.AddConnection(&mountain);
    village.AddConnection(&chasm);
    village.AddConnection(&home); //one way connection

    chasm.AddConnection(&mountain);
    chasm.AddConnection(&village);
    chasm.AddConnection(&tower);

    tower.AddConnection(&chasm);

    meadow.AddConnection(&city);
    meadow.AddConnection(&forest);
    meadow.AddConnection(&swamp);

    forest.AddConnection(&meadow);
    forest.AddConnection(&swamp);
    forest.AddConnection(&waterfall);
    forest.AddConnection(&ruins);

    waterfall.AddConnection(&forest);
    waterfall.AddConnection(&ruins);

    ruins.AddConnection(&forest);
    ruins.AddConnection(&waterfall);

    swamp.AddConnection(&meadow);
    swamp.AddConnection(&forest);
    swamp.AddConnection(&graveyard);
    swamp.AddConnection(&volcano);

    graveyard.AddConnection(&swamp);
    graveyard.AddConnection(&volcano);

    volcano.AddConnection(&swamp);
    volcano.AddConnection(&graveyard);
    volcano.AddConnection(&castle);

    castle.AddConnection(&volcano);

    // build map in same order as Node Ids above.
    // The index of each node in the vector must match it's id.
    gameMap.push_back(home);
    gameMap.push_back(mountain);
    gameMap.push_back(city);
    gameMap.push_back(ocean);
    gameMap.push_back(island);
    gameMap.push_back(hut);
    gameMap.push_back(quicksand);
    gameMap.push_back(village);
    gameMap.push_back(chasm);
    gameMap.push_back(tower);
    gameMap.push_back(meadow);
    gameMap.push_back(forest);
    gameMap.push_back(waterfall);
    gameMap.push_back(ruins);
    gameMap.push_back(swamp);
    gameMap.push_back(graveyard);
    gameMap.push_back(volcano);
    gameMap.push_back(castle);

    // build assets
    //
    Asset flashlight("Flashlight", "A flashlight can be very useful, especially in dark places.", 50, false);
    Asset hammer("Hammer", "A hammer to help defend yourself", 150, true);
    Asset purplehaze("Purple haze", "A spell that renders opponents helpless.", 250, true);
    Asset rustynail("Rusty nail", "Infect an opponent with tetanus.", 100, true);
    Asset drinkingwater("Drinking water", "This may keep you from going thirsty.", 50, false);

    // randomly add assets to nodes
    int numOfNodes = gameMap.size();

    srand(time(nullptr)); // seed the random number generator
    int randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&flashlight);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&hammer);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&purplehaze);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&rustynail);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddAsset(&drinkingwater);

    // build monsters
    // randomly add monsters to nodes
    Monster ghoul("ghoul", 5000, 100);
    Monster goblin("goblin", 6000, 100);
    Monster kraken("kraken", 7000, 100);
    Monster demon("demon", 5000, 100);
    Monster griffin("griffin", 4000, 100);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&ghoul);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&goblin);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&kraken);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&demon);

    randNode = rand() % numOfNodes;
    gameMap[randNode].AddMonster(&griffin);

    // get ready to play game below
    int nodePointer = 0; // start at home
    string input;

    // +++++++++ game loop ++++++++++
    while (true)
    {
        // show current node info
        AtNode(gameMap[nodePointer]);

        cout << "Go to node? e(x)it: ";
        getline(cin, input);

        // exit app?
        if (input == "x")
            break;

        int nodeAddr = -1;
        if (isNumber(input))
        {
            nodeAddr = stoi(input);
        }

        bool validConnection = false;
        for (Node *node : gameMap[nodePointer].GetConnections())
        {
            if (node->GetId() == nodeAddr)
            {
                validConnection = true;
            }
        }

        int dir = -1;
        if (validConnection)
        {
            dir = FindNode(input, &gameMap);
        }

        // if player wants to take an asset (t hammer)
        if (input.length() > 1 && input[0] == 't')
        {
            string lastWord = getLastWord(input);
        }

        // if player wants to attack a monster (a kraken)
        if (input.length() > 1 && input[0] == 'a')
        {
            string lastWord = getLastWord(input);
        }

        // if player wants to drop an asset (d hammer)
        if (input.length() > 1 && input[0] == 'd')
        {
            string lastWord = getLastWord(input);
        }

        // if player wants to inspect an asset (i hammer)
        if (input.length() > 1 && input[0] == 'i')
        {
            string lastWord = getLastWord(input);
        }

        cout << "Dir: " << dir << endl;
        if (dir >= 0)
            nodePointer = dir;
        else
            cout << "Not a valid node address\n";

        cout << endl;
    }
    return 0;
}
