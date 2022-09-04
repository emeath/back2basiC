#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_ATTEMPS 5
#define INITIAL_SCORE 1000

int main() {

	// print game header
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~ Welcome to our guessing number game! :) ~\n"); 	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("\n\n");
	printf("       quu.._                                                                       \n");
	printf("        $$$b  `---.__                                                               \n");
	printf("         \"$$b        `--.                          ___.---uuudP                    \n");
	printf("          `$$b           `.__.------.__     __.---'      $$$$\"              .      \n");
	printf("           \"$b          -'            `-.-'            $$$\"              .'|      \n");
	printf("             \".                                       d$\"             _.'  |      \n");
	printf("                `.   /                              ...\"             .'     |      \n");
	printf("                  `./                           ..::-'            _.'       |       \n");
	printf("                   /                         .:::-'            .-'         .'       \n");
	printf("                  :                          ::''\\          _.'            |       \n");
	printf("                 .' .-.             .-.           `.      .'               |        \n");
	printf("                 : /'$$|           .@\"$\\           `.   .'              _.-'      \n");
	printf("                .'|$u$$|          |$$,$$|           |  <            _.-'            \n");
	printf("                | `:$$:'          :$$$$$:           `.  `.       .-'                \n");
	printf("                :                  `\"--'             |    `-.     \\               \n");
	printf("               :##.       ==             .###.       `.      `.    `\\              \n");
	printf("               |##:                      :###:        |        >     >              \n");
	printf("               |#'     `..'`..'          `###'        x:      /     /               \n");
	printf("                \\                                   xXX|     /    ./               \n");
	printf("                 \\                                xXXX'|    /   ./                 \n");
	printf("                 /`-.                                  `.  /   /                    \n");
	printf("                :    `-  ...........,                   | /  .'                     \n");
	printf("                |         ``:::::::'       .            |<    `.                    \n");
	printf("                |             ```          |           x| \\ `.:``.                 \n");
	printf("                |                         .'    /'   xXX|  `:`M`M':.                \n");
	printf("                |    |                    ;    /:' xXXX'|  -'MMMMM:'                \n");
	printf("                `.  .'                   :    /:'       |-'MMMM.-'                  \n");
	printf("                 |  |                   .'   /'        .'MMM.-'                     \n");
	printf("                 `'`'                   :  ,'          |MMM<                        \n");
	printf("                   |                     `'            |tbap\\                      \n");
	printf("                    \\                                  :MM.-'                      \n");
	printf("                     \\                 |              .''                          \n");
	printf("                      \\.               `.            /                             \n");
	printf("                       /     .:::::::.. :           /                               \n");
	printf("                      |     .:::::::::::`.         /                                \n");
	printf("                      |   .:::------------\\       /                                \n");
	printf("                     /   .''               >::'  /                                  \n");
	printf("                     `',:                 :    .'                                   \n");
	printf("                                          `:.:' Tim Park                            \n");
	printf("                                                                                    \n");
	printf("\n\n");
	
	int secondsSince1970 = time(0);
	srand(secondsSince1970);	
	int secretNumber = rand() % 1000; // numbers from 0 to 1000

	int guess;
	int attempt = 1;
	int difficulty;
	printf("Select the game difficulty:\n");
	printf("(1) Easy (2) Normal (3) Hard\n");
	printf(">> ");
	scanf("%d", &difficulty);

	int lives;
	
	switch(difficulty) {
		case 1:
			lives = 20;
			break;
		case 2:
			lives = 10;
			break;
		default:
			lives = 5;
			break;
	}

	int correctGuess;

	double score = INITIAL_SCORE;
	for(int i = 0; i < lives; i++) {
		printf("Attempt %d\n", attempt);
		printf("What is your guess number? ");
		scanf("%d", &guess);
		printf("Your guess is: %d\n", guess);

		if(guess < 0) {
			printf("You can not guess negative numbers!\n");
			i--; // the player will not lose his life on this scenario;
			continue;
		}

		correctGuess = (guess == secretNumber);
		int bigger = (guess > secretNumber);

		if(correctGuess) {
			break;
		} else if(bigger) {
			printf("Your guess is bigger than the secret number!\n");
		} else {
			printf("Your guess is smaller than the secret number!\n");
		}

		attempt++;

		// compute score
		score = score - abs(secretNumber - guess)/2.0;
	}

	printf("Game over!\n");
	if(correctGuess) {
		printf("Congratulations! You got it!\n");
		printf("You should play again. You are such a good player! :D\n");
		printf("You won with #%d attempts!\n", attempt);
		printf("You scored: %.2f points!\n", score);
		printf("\n\n\n\n");

		printf("                      _,........_                                                                   \n");
		printf("                   ,-'            \"`-.                                                             \n");
		printf("                 ,'                   `-.                                                           \n");
		printf("               ,'                        \\                                                         \n");
		printf("             ,'                           .                                                         \n");
		printf("             .'\\               ,\"\".       `                                                      \n");
		printf("            ._.'|             / |  `       \\                                                       \n");
		printf("            |   |            `-.'  ||       `.                                                      \n");
		printf("            |   |            '-._,'||       | \\                                                    \n");
		printf("            .`.,'             `..,'.'       , |`-.                                                  \n");
		printf("            l                       .'`.  _/  |   `.                                                \n");
		printf("            `-.._'-   ,          _ _'   -\" \\  .     `                                             \n");
		printf("       `.\"\"\"\"\"'-.`-...,---------','         `. `....__.                                        \n");
		printf("       .'        `\"-..___      __,'\\          \\  \\     \\                                       \n");
		printf("       \\_ .          |   `\"\"\"\"'    `.           . \\     \\                                    \n");
		printf("         `.          |              `.          |  .     L                                          \n");
		printf("           `.        |`--...________.'.        j   |     |                                          \n");
		printf("             `._    .'      |          `.     .|   ,     |                                          \n");
		printf("                `--,\\       .            `7\"\"' |  ,      |                                       \n");
		printf("                   ` `      `            /     |  |      |    _,-'\"\"\"`-.                         \n");
		printf("                    \\ `.     .          /      |  '      |  ,'          `.                         \n");
		printf("                     \\  v.__  .        '       .   \\    /| /              \\                      \n");
		printf("                      \\/    `\"\"\\\"\"\"\"\"\"\"`.       \\   \\  /.''                |           \n");
		printf("                       `        .        `._ ___,j.  `/ .-       ,---.     |                        \n");
		printf("                       ,`-.      \\         .\"     `.  |/        j     `    |                      \n");
		printf("                      /    `.     \\       /         \\ /         |     /    j                      \n");
		printf("                     |       `-.   7-.._ .          |\"          '         /                        \n");
		printf("                     |          `./_    `|          |            .     _,'                          \n");
		printf("                     `.           / `----|          |-............`---'                             \n");
		printf("                       \\          \\      |          |                                             \n");
		printf("                      ,'           )     `.         |                                               \n");
		printf("                       7____,,..--'      /          |                                               \n");
		printf("                                         `---.__,--.'mh                                             \n");
		printf("                                                                                                    \n");
		printf("\n\n\n\n");
	} else {
		printf("try again!\n");

		printf("\n\n");
		printf("                        .\"-,._                                                            \n");
		printf("                        `.     `.  ,                                                       \n");
		printf("                     .--'  .._,'\"-' `.                                                    \n");
		printf("                    .    .'         `'                                                     \n");
		printf("                    `.   /          ,'                                                     \n");
		printf("                      `  '--.   ,-\"'                                                      \n");
		printf("                       `\"`   |  \\                                                        \n");
		printf("                          -. \\, |                                                         \n");
		printf("                           `--Y.'      ___.                                                \n");
		printf("                                \\     L._, \\                                             \n");
		printf("                      _.,        `.   <  <\\                _                              \n");
		printf("                    ,' '           `, `.   | \\            ( `                             \n");
		printf("                 ../, `.            `  |    .\\`.           \\ \\_                         \n");
		printf("                ,' ,..  .           _.,'    ||\\l            )  '\".                       \n");
		printf("               , ,'   \\           ,'.-.`-._,'  |           .  _._`.                       \n");
		printf("             ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\                   \n");
		printf("           .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.                   \n");
		printf("           |  '          ..         `-...-\"  |  `-'      / /        . `.                  \n");
		printf("           | /           |L__           |    |          / /          `. `.                 \n");
		printf("          , /            .   .          |    |         / /             ` `                 \n");
		printf("         / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\               \n");
		printf("        / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.           \n");
		printf("       .  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\           \n");
		printf("       ' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`             \n");
		printf("       |'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\       \n");
		printf("       ||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|             \n");
		printf("       ||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||             \n");
		printf("       || '              V      / /           `   | `   ,'   ,' '.    !  `. ||             \n");
		printf("       ||/            _,-------7 '              . |  `-'    l         /    `||             \n");
		printf("       . |          ,' .-   ,' ||               | .-.        `.      .'     ||             \n");
		printf("        `'        ,'    `\".'    |               |    `.        '. -.'       `'            \n");
		printf("                 /      ,'      |               |,'    \\-.._,.'/'                         \n");
		printf("                 .     /        .               .       \\    .''                          \n");
		printf("               .`.    |         `.             /         :_,'.'                            \n");
		printf("                 \\ `...\\   _     ,'-.        .'         /_.-'                            \n");
		printf("                  `-.__ `,  `'   .  _.>----''.  _  __  /                                   \n");
		printf("                       .'        /\"'          |  \"'   '_                                 \n");
		printf("                      /_|.-'\\ ,\".             '.'`__'-( \\                               \n");
		printf("                        / ,\"'\"\\,'               `/  `-.|\" mh                           \n");
		printf("                                                                                           \n");
		printf("                                                                                           \n");
		printf("\n\n");


	}
	return 0;
	
}
