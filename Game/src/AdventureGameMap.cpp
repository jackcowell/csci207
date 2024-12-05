/// @file AdventureGameMap.cpp
/// @brief Implementation of the AdventureGameMap class for the adventure game project.
///
/// This file defines the AdventureGameMap class, which builds and manages the nodes and connections that form the map of the game. 
/// Each node represents a location, with descriptions and connections to other nodes.



#include <AdventureGameMap.hpp>

namespace chants
{
    /// @class AdventureGameMap
    /// @brief This class is what creates the map for the game. 
    ///
    /// This class creates the nodes and their connections to other nodes, which allows the player to navigate through the map of the game,
    /// This map includes 20 different locations each having a description to go along with it. 
    AdventureGameMap::AdventureGameMap()
    {
        buildMapNodes();

        // Possible assets:
        // Flashlight
        // Atomic Map
        // Compass
        // Screwdriver
        // Hammer
        // Polyglot (translator)
        // Treasure
        // Hobgoblin Shield
        // Garden Hose
        // Chest
        // Sign
        // Rabbit Cage
        // Paper Bag
        // Captain’s Chair
        // Purple Haze
        // Drinking Glass
        // Rusty Nail

        // Possible monsters:
        //
    }

    /// @brief Constructs the nodes and the connections.
    ///
    /// This function creates every location and provides their description, as well as the connections between each location. 
    void AdventureGameMap::buildMapNodes()
    {
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
        locations.push_back(home);
        locations.push_back(mountain);
        locations.push_back(city);
        locations.push_back(ocean);
        locations.push_back(island);
        locations.push_back(hut);
        locations.push_back(quicksand);
        locations.push_back(cave);
        locations.push_back(beach); // NOTE: game.cpp excludes cave and beach, mistake or intentional?
        locations.push_back(village);
        locations.push_back(chasm);
        locations.push_back(tower);
        locations.push_back(meadow);
        locations.push_back(forest);
        locations.push_back(waterfall);
        locations.push_back(ruins);
        locations.push_back(swamp);
        locations.push_back(graveyard);
        locations.push_back(volcano);
        locations.push_back(castle);  
        }
    /// @brief This gathers all of the locations on the map
    /// @return  This returns a vector of the node objects (locations).
    ///
    /// This function serves to provide access to the list of all locations on the game map. 
    vector<Node> AdventureGameMap::GetLocations()
    {
        return locations;
    }

}
