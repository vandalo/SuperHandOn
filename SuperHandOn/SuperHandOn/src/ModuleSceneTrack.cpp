#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleFont.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneTrack.h"
#include "ModulePlayer.h"
#include "Line.h"
#include <string>

ModuleSceneTrack::ModuleSceneTrack(bool active) : Module(active)
{
	sempahorYellow = { 463,250,75,32 };
	sempahorBlue = { 463,283,75,32 };
	backgroundTop = {33, 437, 62, 25};
	backgroundTime = { 97, 437, 76, 26 };
	backgroundScore = { 175, 437, 98, 26 };
	backgroundStage = { 275, 421, 83, 18 };
	backgroundStageProces = { 33, 467, 226, 18 };
	backgroundCourse = { 409, 421, 98, 18 };
	backgroundSpeed = { 275, 441, 82, 18 };
	backgroundKm = { 367, 441, 34, 18 };
	finishPose = { 634, 1399, 96, 145 };
	checkFill = { 51, 552, 31, 4 };
	gameOver = { 1154,249,180,30 };
	extendedPlay = { 1155,295,152,16 };
	beginnerCourse = { 1156, 314, 219, 15 };

	dictionari = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "<" };

	//Animation of IA
	//Green
	greenZero.frames.push_back({ 689,915,128,110 });
	greenZero.frames.push_back({ 819,915,128,110 });
	greenZero.loop = true;
	greenZero.speed = 0.04f;

	greenOne.frames.push_back({ 589,899,92,126 });
	greenOne.frames.push_back({ 487,899,92,126 });
	greenOne.loop = true;
	greenOne.speed = 0.04f;

	greenTwo.frames.push_back({ 411,889,72,136 });
	greenTwo.frames.push_back({ 335,889,72,136 });
	greenTwo.loop = true;
	greenTwo.speed = 0.04f;

	greenThree.frames.push_back({ 257,879,66,146 });
	greenThree.frames.push_back({ 181,879,66,146 });
	greenThree.loop = true;
	greenThree.speed = 0.04f;

	greenFour.frames.push_back({ 859,1215,72,142 });
	greenFour.frames.push_back({ 783,1215,72,142 });
	greenFour.loop = true;
	greenFour.speed = 0.04f;

	greenFive.frames.push_back({ 687,1231,92,126 });
	greenFive.frames.push_back({ 585,1231,92,126 });
	greenFive.loop = true;
	greenFive.speed = 0.04f;

	greenSix.frames.push_back({ 451,1247,126,110 });
	greenSix.frames.push_back({ 321,1247,126,110 });
	greenSix.loop = true;
	greenSix.speed = 0.04f;

	//Yellow
	yellowZero.frames.push_back({ 819,1075,126,110 });
	yellowZero.frames.push_back({ 689,1075,126,110 });
	yellowZero.loop = true;
	yellowZero.speed = 0.04f;

	yellowOne.frames.push_back({ 589,1059,92,126 });
	yellowOne.frames.push_back({ 487,1059,92,126 });
	yellowOne.loop = true;
	yellowOne.speed = 0.04f;

	yellowTwo.frames.push_back({ 411,1043,72,136 });
	yellowTwo.frames.push_back({ 335,1043,72,136 });
	yellowTwo.loop = true;
	yellowTwo.speed = 0.04f;

	yellowThree.frames.push_back({ 257,1039,66,146 });
	yellowThree.frames.push_back({ 181,1039,66,146 });
	yellowThree.loop = true;
	yellowThree.speed = 0.04f;

	yellowFour.frames.push_back({ 859,1375,72,142 });
	yellowFour.frames.push_back({ 859,1375,72,142 });
	yellowFour.loop = true;
	yellowFour.speed = 0.04f;

	yellowFive.frames.push_back({ 687,1390,92,126 });
	yellowFive.frames.push_back({ 585,1390,92,126 });
	yellowFive.loop = true;
	yellowFive.speed = 0.04f;

	yellowSix.frames.push_back({ 451,1407,126,110 });
	yellowSix.frames.push_back({ 321,1407,126,110 });
	yellowSix.loop = true;
	yellowSix.speed = 0.04f;

	//finishPlayer
	finishPlayer.frames.push_back({ 181, 559, 66, 146 });
	finishPlayer.frames.push_back({ 257, 559, 66, 146 });
	finishPlayer.loop = true;
	finishPlayer.speed = 0.04f;
}

ModuleSceneTrack::~ModuleSceneTrack()
{}

// Load assets
bool ModuleSceneTrack::Start()
{
	LOG("Loading space intro");
	debugMode = false;
	debugRoad = false;
	stage = 1;
	time = 50;
	score = 0;
	speed = 0;
	startTime = 0;
	lapTime = 0;
	totalTime = 0;
	dictionariPosition = 0;
	N = 0;
	pos = 0;
	realPos = 0;
	startTime = 0;
	timeBonus = 3;
	timeGameOver = 2;
	sempahorState = 0;
	puntuationPoistion = 9;
	swapLeter = 0;
	playerX = 0;
	firstLoop = true;
	run = false;
	biomSwap = false;
	biomSwapBackgroundHelper = false;
	updatedPuntuation = false;

	finished = RUNNING;

	Enemy* enemy = new Enemy();
	enemy->color = GREEN;
	enemy->speed = 300;
	enemy->posStopSprint = 650;
	enemy->posZ = 11;
	enemy->posX = -0.4f;
	enemy->position = 3;
	enemy->current_animation = &greenThree;
	enemys.push_back(enemy);

	Enemy* enemy2 = new Enemy();
	enemy2->color = GREEN;
	enemy2->speed = 270;
	enemy2->posStopSprint = 1300;
	enemy2->posZ = 11;
	enemy2->posX = 0.4f;
	enemy2->position = 3;
	enemy2->current_animation = &greenThree;
	enemys.push_back(enemy2);

	Enemy* enemy3 = new Enemy();
	enemy3->color = YELLOW;
	enemy3->speed = 270;
	enemy3->posStopSprint = 1100;
	enemy3->posZ = 13;
	enemy3->posX = 0.0f;
	enemy3->position = 3;
	enemy3->current_animation = &yellowThree;
	enemys.push_back(enemy3);

	Enemy* enemy4 = new Enemy();
	enemy4->color = YELLOW;
	enemy4->speed = 270;
	enemy4->posStopSprint = 900;
	enemy4->posZ = 9;
	enemy4->posX = -0.7f;
	enemy4->position = 3;
	enemy4->current_animation = &yellowThree;
	enemys.push_back(enemy4);

	Enemy* enemy5 = new Enemy();
	enemy5->color = YELLOW;
	enemy5->speed = 270;
	enemy5->posStopSprint = 1550;
	enemy5->posZ = 9;
	enemy5->posX = 0.7f;
	enemy5->position = 3;
	enemy5->current_animation = &yellowThree;
	enemys.push_back(enemy5);

	finishAnimation = new Enemy();
	finishAnimation->color = YELLOW;
	finishAnimation->speed = 270;
	finishAnimation->posStopSprint = 1550;
	finishAnimation->posZ = 0;
	finishAnimation->posX = 0.0f;
	finishAnimation->position = 3;
	finishAnimation->current_animation = &finishPlayer;

	mostAdvancedEnemyZ = 1550;

	//Decoration
	Decoration*dec_tree = new Decoration();
	dec_tree->maxX = 4;
	dec_tree->minX = 2.5;
	dec_tree->rect = { 649, 0, 138, 209 };
	decoration.push_back(dec_tree);
	deadTree = decoration.size() - 1;

	Decoration*dec_signLeft = new Decoration();
	dec_signLeft->maxX = 4;
	dec_signLeft->minX = 2.5;
	dec_signLeft->rect = { 961, 31, 173, 122 };
	decoration.push_back(dec_signLeft);
	signLeft = decoration.size() - 1;

	Decoration*dec_signRight = new Decoration();
	dec_signRight->maxX = 4;
	dec_signRight->minX = 2.5;
	dec_signRight->rect = { 1164, 28, 173, 126 };
	decoration.push_back(dec_signRight);
	signRight = decoration.size() - 1;

	Decoration*dec_tonnel = new Decoration();
	dec_tonnel->maxX = 4;
	dec_tonnel->minX = 2.5;
	dec_tonnel->rect = { 1517, 178, 175, 170 };
	decoration.push_back(dec_tonnel);
	tonnel = decoration.size() - 1;

	Decoration*dec_bidalstone = new Decoration();
	dec_bidalstone->maxX = 4;
	dec_bidalstone->minX = 2.5;
	dec_bidalstone->rect = { 1377, 37, 431, 120 };
	decoration.push_back(dec_bidalstone);
	bidalstone = decoration.size() - 1;

	Decoration*dec_rock = new Decoration();
	dec_rock->maxX = 4;
	dec_rock->minX = 2.5;
	dec_rock->rect = { 1290, 358, 356, 168 };
	decoration.push_back(dec_rock);
	rock = decoration.size() - 1;

	Decoration*dec_startSign = new Decoration();
	dec_startSign->maxX = 0;
	dec_startSign->minX = 0;
	dec_startSign->rect = { 17, 426, 834, 278 };
	decoration.push_back(dec_startSign);
	startSign = decoration.size() - 1;

	Decoration*dec_checkSign = new Decoration();
	dec_checkSign->maxX = 0;
	dec_checkSign->minX = 0;
	dec_checkSign->rect = { 13, 721, 840, 279 };
	decoration.push_back(dec_checkSign);
	checkSign = decoration.size() - 1;

	Decoration*dec_biomSwap = new Decoration();
	dec_biomSwap->maxX = 0;
	dec_biomSwap->minX = 0;
	dec_biomSwap->rect = { 2200, 2200, 840, 279 };
	decoration.push_back(dec_biomSwap);
	biomSwapPoint = decoration.size() - 1;

	Decoration*dec_bushTree = new Decoration();
	dec_bushTree->maxX = 4;
	dec_bushTree->minX = 2.5;
	dec_bushTree->rect = { 1152, 1001, 241, 212 };
	decoration.push_back(dec_bushTree);
	bushTree = decoration.size() - 1;

	Decoration*dec_birdbird = new Decoration();
	dec_birdbird->maxX = 4;
	dec_birdbird->minX = 2.5;
	dec_birdbird->rect = { 949, 178, 284, 165 };
	decoration.push_back(dec_birdbird);
	birdbird = decoration.size() - 1;

	Decoration*dec_palmTree = new Decoration();
	dec_palmTree->maxX = 3;
	dec_palmTree->minX = 2;
	dec_palmTree->rect = { 955, 852, 172, 420 };
	decoration.push_back(dec_palmTree);
	palmTree = decoration.size() - 1;

	Decoration*dec_cactus = new Decoration();
	dec_cactus->maxX = 3;
	dec_cactus->minX = 2;
	dec_cactus->rect = { 1718, 276, 204, 169 };
	decoration.push_back(dec_cactus);
	cactus = decoration.size() - 1;

	Decoration*dec_goalSign = new Decoration();
	dec_goalSign->maxX = 0;
	dec_goalSign->minX = 0;
	dec_goalSign->rect = { 7, 1003, 852, 311 };
	decoration.push_back(dec_goalSign);
	goalSign = decoration.size() - 1;

	Decoration*dec_people = new Decoration();
	dec_people->maxX = 0;
	dec_people->minX = 0;
	dec_people->rect = { 21, 1357, 548, 184 };
	decoration.push_back(dec_people);
	people = decoration.size() - 1;

	//ON DEBUG MODE
	/*App->menusFont = App->font->LoadMedia("fonts/font18x30.png", "9876543210", 18, 30);
	App->fxLoadTrack = App->audio->LoadFx("resources/music/fxLoadTrack.wav");
	App->fxSemaphorOne = App->audio->LoadFx("resources/music/fxSempahorOne.wav");
	App->fxSemaphorFinish = App->audio->LoadFx("resources/music/fxSempahorFinish.wav");*/


	//Load decorations
	App->audio->PlayFx(App->fxLoadTrack);
	graphics = App->textures->Load("resources/sprites/backgrounds.png");

	gui = App->textures->Load("resources/sprites/miscellaneous.png");

	//Load decoration sprites
	decorationSprite = App->textures->Load("resources/sprites/decoration.png");

	//Gui fonts
	App->numericFontYellow = App->font->LoadMedia("resources/fonts/fontNumber18x18.png", "1234567890SEC'\" ", 16, 18);
	App->numericFontWhite = App->font->LoadMedia("resources/fonts/fontNumber18x18.png", "1234567890*=ABCDEFGHIJKLMNOPQRSTUVWXYZ< ", 16, 18, 18);
	App->numericFontRed = App->font->LoadMedia("resources/fonts/fontNumber18x18.png", "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ'\" ", 16, 18, 36);
	App->numericFontGreen = App->font->LoadMedia("resources/fonts/fontNumber18x18.png", "1234567890< ", 16, 18, 54);

	App->player->Enable();
	//App->enemy->Enable();
	return true;
}

// UnLoad assets
bool ModuleSceneTrack::CleanUp()
{
	LOG("Unloading space scene");
	for (unsigned int i = 0; i < enemys.size(); i++) delete(enemys[i]);
	enemys.clear();
	for (unsigned int i = 0; i < decoration.size(); i++) delete(decoration[i]);
	decoration.clear();
	for (unsigned int i = 0; i < bioms.size(); i++) delete(bioms[i]);
	bioms.clear();
	delete(finishAnimation);

	saveScore();

	App->textures->Unload(graphics);
	return true;
}

void ModuleSceneTrack::PrintTrack(float deltaTime)
{
	while (pos >= N * 200) pos -= N * SEGL;
	while (pos < 0) pos += N * SEGL;

	float x = 0, dx = 0;
	int segL = SEGL;
	int startPos = (int)(pos / segL);
	int camH = (int)(1500 + lines[startPos].y);
	int maxy = HEIGHT;

	//Draw background
	float paralaxMovment = 0;
	if (finished == RUNNING)paralaxMovment = 0.3f;
	App->renderer->Blit(graphics, 0, 0, &background, 0.0f);
	if (biomSwapBackgroundHelper)App->renderer->DrawPoly(sky, 0, 0, SCREEN_WIDTH, 0, 300, SCREEN_WIDTH);
	App->renderer->Blit(graphics, 0, SCREEN_HEIGHT / 2 + 7, &backgroundParalax, paralaxMovment, true);
	App->renderer->Blit(graphics, 610, SCREEN_HEIGHT / 2 + 7, &backgroundParalax, paralaxMovment, true);
	App->renderer->Blit(graphics, -610, SCREEN_HEIGHT / 2 + 7, &backgroundParalax, paralaxMovment, true);

	//Draw track
	for (int n = startPos; n < startPos + 300; n++) {
		Line &l = lines[n%N];
		l.project((int)(playerX - x), camH, pos - (n >= N ? N * segL : 0));

		//Check if player is out of road
		if (n-1 == startPos) {
			if (playerX > l.W || playerX < -l.W) {
				if(speed > MIN_VEL) speed -= acceleration * deltaTime * 2;
				if (!App->player->isOutofRoad) {
					App->player->isOutofRoad = true;
					App->player->outOfRoad.Reset();
				}
			}
			else {
				App->player->isOutofRoad = false;
			}
		}
		x += dx;
		dx += l.curve;

		l.clip = (float)maxy;
		if (l.Y >= maxy) continue;
		maxy = (int)(l.Y);

		Color grass = (n / 3) % 2 ? grass1 : grass2;
		Color rumble = (n / 3) % 2 ? rumble1 : rumble2;
		Color line = (n / 10) % 2 ? color_line1 : color_line2;
		Color road = (n / 10) % 2 ? color_road1 : color_road2;

		if (n == 0)n++;
		Line p = lines[(n - 1) % N]; //previous line

		App->renderer->DrawPoly(grass, 0, (short)p.Y, (short)p.width, 0, (short)l.Y, (short)l.width);
		App->renderer->DrawPoly(rumble, (short)p.X, (short)p.Y, (short)(p.W*1.2), (short)l.X, (short)l.Y, (short)(l.W*1.2));
		App->renderer->DrawPoly(road, (short)p.X, (short)p.Y, (short)p.W, (short)l.X, (short)l.Y, (short)l.W);
		App->renderer->DrawPoly(line, (short)p.X, (short)p.Y, (short)(p.W*0.05), (short)l.X, (short)l.Y, (short)(l.W*0.05));
		
	}

	//Draw Objects
	for (int n = startPos + 300; n > startPos; n--) {
		if (lines[n%N].id != -1) {
			if ((startPos + 10) > n && n > (startPos + 5) && checkSign == lines[n%N].id && delayCheckPoint == 0) {
				time += 25;
				if (lapTime < stageTimeSaved[stage - 1]) stageTimeSaved[stage - 1] = lapTime;
				delayCheckPoint += 5;
				checkTime = 5;
				lastLapTime = lapTime;
				lapTime = 0;
				stage++;
			}
			else if((startPos + 10) > n && n > (startPos + 5) && goalSign == lines[n%N].id && finished == RUNNING) {
				finished = ANIMATION;
				stage++;
				finishAnimation->posZ = (float)(startPos + 7);
				goalPos = finishAnimation->posZ;
			}
			else if ((startPos + 10) > n && n > (startPos + 5) && biomSwapPoint == lines[n%N].id && !biomSwap) {
				biomSwap = true;
				currentBiomId++;
				updateBiomTimer = 0;
			}
			else 
				lines[n%N].DrawObject(decoration[lines[n%N].id]->rect, decorationSprite, 999.0f, false, (startPos + 10) > n && n > (startPos + 5) && startSign != lines[n%N].id && biomSwapPoint != lines[n%N].id);
		}
			
	}
	if (finished == RUNNING) {
		//Sempahor animation
		if (startTime != -1) {
			if (firstLoop) firstLoop = false;
			else {
				startTime += deltaTime;
				if (startTime < 4) {
					if (startTime < 3) {
						App->renderer->Blit(decorationSprite, 14, SCREEN_HEIGHT / 2 + 19 + 62, &sempahorYellow, 0.f);
						if (sempahorState == 0 && startTime > 2)sempahorState++;
					}
					else {
						App->renderer->Blit(decorationSprite, 14, SCREEN_HEIGHT / 2 + 19 + 31, &sempahorYellow, 0.f);
						if (sempahorState == 2)sempahorState++;
					}
				}
				if (startTime < 4) {
					App->renderer->Blit(decorationSprite, 14, SCREEN_HEIGHT / 2 + 19, &sempahorBlue, 0.f);
				}
				else if (startTime < 5) {
					if (sempahorState == 4) sempahorState++;
				}
				else if (startTime > 5) {
					startTime = -1;
					run = true;
					switch (App->musicChosed)
					{
					case OUTRIDE_A_CRISIS:
						App->musicChosed = OUTRIDE_A_CRISIS;
						App->audio->PlayMusic("resources/music/2OutrideaCrisis.ogg", 0.f);
						break;
					case SPRINTER:
						App->musicChosed = SPRINTER;
						App->audio->PlayMusic("resources/music/3Sprinter.ogg", 0.f);
						break;
					case WINNING_RUN:
						App->musicChosed = WINNING_RUN;
						App->audio->PlayMusic("resources/music/4WinningRun.ogg", 0.f);
						break;
					case HARD_ROAD:
						App->musicChosed = HARD_ROAD;
						App->audio->PlayMusic("resources/music/5HardRoad.ogg", 0.f);
						break;
					default:
						break;
					}
				}
			}
			if (sempahorState == 1 || sempahorState == 3) {
				App->audio->PlayFx(App->fxSemaphorOne);
				sempahorState++;
			}
			else if (sempahorState == 5) {
				App->audio->PlayFx(App->fxSemaphorFinish);
				sempahorState++;
			}
		}

		//Draw Enemys
		for (unsigned int n = 0; n < enemys.size(); n++) {
			if (enemys[n]->posZ > startPos) {
				float enemysCurve = lines[(int)(enemys[n]->posZ) % N].curve;
				bool animationChanged = false;
				if (enemysCurve < -3) {
					animationChanged = TrentToN(0, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				else if (enemysCurve < -1.5) {
					animationChanged = TrentToN(1, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				else if (enemysCurve < 0) {
					animationChanged = TrentToN(2, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				else if (enemysCurve > 3) {
					animationChanged = TrentToN(6, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				else if (enemysCurve > 1.5) {
					animationChanged = TrentToN(5, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				else if (enemysCurve > 0) {
					animationChanged = TrentToN(4, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				else {
					animationChanged = TrentToN(3, enemys[n]->position, deltaTime, enemys[n]->animationTime);
				}
				if (animationChanged) {
					switch (enemys[n]->position) {
					case 0:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowZero;
						else enemys[n]->current_animation = &greenZero;
						break;
					case 1:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowOne;
						else enemys[n]->current_animation = &greenOne;
						break;
					case 2:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowTwo;
						else enemys[n]->current_animation = &greenTwo;
						break;
					case 3:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowThree;
						else enemys[n]->current_animation = &greenThree;
						break;
					case 4:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowFour;
						else enemys[n]->current_animation = &greenFour;
						break;
					case 5:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowFive;
						else enemys[n]->current_animation = &greenFive;
						break;
					case 6:
						if (enemys[n]->color == YELLOW) enemys[n]->current_animation = &yellowSix;
						else enemys[n]->current_animation = &greenSix;
						break;
					default:
						break;
					}
				}
				lines[(int)(enemys[n]->posZ) % N].DrawObject(enemys[n]->current_animation->GetCurrentFrame(), gui, enemys[n]->posX);
			}
		}
	}
	else {
		if (finishAnimation->posZ < goalPos + 150) {
			finishAnimation->posZ += deltaTime * 75;
			lines[(int)(finishAnimation->posZ) % N].DrawObject(finishAnimation->current_animation->GetCurrentFrame(), gui, 0);
		}
		else if (pos < (goalPos + 140) *segL) {
				realPos += (int)(deltaTime * 75 * 100);
				if (realPos > 200) {
					pos += 200 * (realPos / segL);
					realPos -= 200 * (realPos / segL);
					if (playerX > 0)playerX--;
					else if (playerX < 0)playerX++;
				}
				lines[(int)(finishAnimation->posZ) % N].DrawObject(finishPose, decorationSprite, 0);
		}
		else {
			lines[(int)(finishAnimation->posZ) % N].DrawObject(finishPose, decorationSprite, 0);
			if (finished == ANIMATION) {
				finished = BONUS;
				App->audio->PlayMusic("resources/music/6Finished.ogg", 0.f);
			}
		}

		App->player->Disable();
	}
}

void ModuleSceneTrack::PrintGui(float deltaTime) 
{
	if (finished != PUNTUATION) {
		App->renderer->Blit(gui, (SCREEN_WIDTH / 10), (SCREEN_HEIGHT / 20), &backgroundTop, 0.f);
		App->renderer->Blit(gui, (SCREEN_WIDTH / 2) - backgroundTime.w / 2, (SCREEN_HEIGHT / 20), &backgroundTime, 0.f);
		App->renderer->Blit(gui, (SCREEN_WIDTH / 10) * 6, (SCREEN_HEIGHT / 20), &backgroundScore, 0.f);
		App->renderer->Blit(gui, (SCREEN_WIDTH / 10), (SCREEN_HEIGHT / 20) * 2 + 8, &backgroundCourse, 0.f);
		App->renderer->Blit(gui, (SCREEN_WIDTH / 10), (SCREEN_HEIGHT / 20) * 3, &backgroundStage, 0.f);
		App->renderer->Blit(gui, (SCREEN_WIDTH / 20), (SCREEN_HEIGHT / 20) * 4, &backgroundStageProces, 0.f);
		App->renderer->Blit(gui, (int)((SCREEN_WIDTH / 10) * 6.5), (int)((SCREEN_HEIGHT / 20) * 2 + 8), &backgroundSpeed, 0.f);
		App->renderer->Blit(gui, (int)((SCREEN_WIDTH / 10) * 8.5) + 16, (int)((SCREEN_HEIGHT / 20) * 2 + 8), &backgroundKm, 0.f);
		App->renderer->Blit(gui, (int)((SCREEN_WIDTH / 10) * 2.7), (int)((SCREEN_HEIGHT / 20) * 2 + 8), &backgroundTrackName, 0.f, false);
		for (int i = 1; i < stage; i++)
			App->renderer->Blit(gui, (SCREEN_WIDTH / 20) + 21 + ((i - 1)*checkFill.w), (SCREEN_HEIGHT / 20) * 4 + 7, &checkFill, 0.f);

		//Text
		App->renderer->Print(App->numericFontRed, to_string((int)maxPuntuation).c_str(), (SCREEN_WIDTH / 10) + backgroundTop.w + 5, (SCREEN_HEIGHT / 20) + 4, 0.f, false);
		App->renderer->Print(App->numericFontGreen, to_string((int)score).c_str(), (SCREEN_WIDTH / 10) * 6 + backgroundScore.w + 5, (SCREEN_HEIGHT / 20) + 4, 0.f, false);
		if (speed < 280)
			App->renderer->Print(App->numericFontWhite, to_string((int)speed).c_str(), (int)((SCREEN_WIDTH / 10) * 6.5) + backgroundSpeed.w, (int)((SCREEN_HEIGHT / 20) * 2 + 8), 0.f, false);
		else
			App->renderer->Print(App->numericFontRed, to_string((int)speed).c_str(), (int)((SCREEN_WIDTH / 10) * 6.5) + backgroundSpeed.w, (int)((SCREEN_HEIGHT / 20) * 2 + 8), 0.f, false);
		App->renderer->Print(App->menusFont, to_string((int)time).c_str(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 20 * 3, 0.f);
		App->renderer->Print(App->numericFontWhite, to_string((int)stage).c_str(), (int)((SCREEN_WIDTH / 10) * 2.4), (int)((SCREEN_HEIGHT / 20) * 3), 0.f, false);

		//DebugMode
		if (debugMode) {
			App->renderer->Print(App->numericFontRed, "DEBUG", (SCREEN_WIDTH / 10), SCREEN_HEIGHT - (SCREEN_HEIGHT / 20), 0.f);
			if(debugRoad) App->renderer->Print(App->numericFontRed, "NO TURN", (SCREEN_WIDTH / 10), SCREEN_HEIGHT - (SCREEN_HEIGHT / 20) * 2, 0.f);
		}
	}
	if (finished == BONUS) {
		App->renderer->Print(App->numericFontRed, "BONUS POINTS", (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 20) * 6, 0.f, true);
		App->renderer->Print(App->menusFont, to_string((int)time).c_str(), (SCREEN_WIDTH / 20) * 5, SCREEN_HEIGHT / 20 * 7, 0.f);
		App->renderer->Print(App->numericFontYellow, "SEC", (SCREEN_WIDTH / 20) * 7, SCREEN_HEIGHT / 20 * 7 + 7, 0.f);
		App->renderer->Print(App->numericFontWhite, "* 1000000 = ", (SCREEN_WIDTH / 20) * 11, SCREEN_HEIGHT / 20 * 7 + 7, 0.f);
		App->renderer->Print(App->menusFont, (to_string((int)time) + '0').c_str(), (SCREEN_WIDTH / 20) * 15, SCREEN_HEIGHT / 20 * 7, 0.f);
		App->renderer->Print(App->numericFontYellow, " 00000", (SCREEN_WIDTH / 20) * 17, SCREEN_HEIGHT / 20 * 7 + 7, 0.f);
		if (timeBonus > 0) timeBonus -= deltaTime;
		if (timeBonus <= 0) {
			finished = PUNTUATION;
			score += (int)(time * 1000000);
		}
	}
	else if (finished == PUNTUATION) {
		if (!updatedPuntuation) {
			bool updated = false;
			int prevScore = 0;
			vector<Score> scores_tmp;
			for (unsigned int i = 0; i < bestScores.size(); i++) {
				if (bestScores[i].score < score && !updated) {
					updated = true;
					Score score_tmp;
					score_tmp.score = score;
					score_tmp.stage = stage;
					score_tmp.name = "";
					score_tmp.time = totalTime;
					puntuationPoistion = i;
					scores_tmp.push_back(score_tmp);
				}
				else {
					if(updated)scores_tmp.push_back(bestScores[i-1]);
					else scores_tmp.push_back(bestScores[i]);
				}
			}
			updatedPuntuation = true;
			bestScores = scores_tmp;
		}
		App->renderer->Blit(gui, (SCREEN_WIDTH / 2) - beginnerCourse.w / 2, (SCREEN_HEIGHT / 20) * 5, &beginnerCourse, 0.f, true);
		App->renderer->Print(App->numericFontWhite, "RANK", (SCREEN_WIDTH / 10), (SCREEN_HEIGHT / 20) * 6, 0.f, true);
		App->renderer->Print(App->numericFontWhite, "SCORE", (SCREEN_WIDTH / 10) * 3, (SCREEN_HEIGHT / 20) * 6, 0.f, true);
		App->renderer->Print(App->numericFontWhite, "STAGE", (SCREEN_WIDTH / 10) * 5, (SCREEN_HEIGHT / 20) * 6, 0.f, true);
		App->renderer->Print(App->numericFontWhite, "NAME", (SCREEN_WIDTH / 10) * 7, (SCREEN_HEIGHT / 20) * 6, 0.f, true);
		App->renderer->Print(App->numericFontWhite, "TIME", (SCREEN_WIDTH / 10) * 9, (SCREEN_HEIGHT / 20) * 6, 0.f, true);
		for (int i = 0; i < 8; i++) {
			if (i == puntuationPoistion) {
				App->renderer->Print(App->numericFontRed, (to_string(i + 1).append("ST")).c_str(), (SCREEN_WIDTH / 10), (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontRed, to_string(bestScores[i].score).c_str(), (SCREEN_WIDTH / 10) * 3, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontRed, to_string(bestScores[i].stage).c_str(), (SCREEN_WIDTH / 10) * 5, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontRed, bestScores[i].name.c_str(), (SCREEN_WIDTH / 10) * 7, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontRed, getTimeFromFloat(bestScores[i].time).c_str(), (SCREEN_WIDTH / 10) * 9, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
			}
			else {
				App->renderer->Print(App->numericFontWhite, (to_string(i + 1).append("ST")).c_str(), (SCREEN_WIDTH / 10), (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontYellow, to_string(bestScores[i].score).c_str(), (SCREEN_WIDTH / 10) * 3, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontYellow, to_string(bestScores[i].stage).c_str(), (SCREEN_WIDTH / 10) * 5, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontWhite, bestScores[i].name.c_str(), (SCREEN_WIDTH / 10) * 7, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
				App->renderer->Print(App->numericFontYellow, getTimeFromFloat(bestScores[i].time).c_str(), (SCREEN_WIDTH / 10) * 9, (SCREEN_HEIGHT / 20) * (7 + i), 0.f, true);
			}
			
		}
		App->renderer->Print(App->numericFontWhite, "ABCDEFGHIJKLMNOPQRSTUVWXYZ<", (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 20) * 16, 0.f, true);
		string letterSelected = "";
		for (unsigned int i = 0; i < dictionari.size(); i++) {
			if (i == dictionariPosition) letterSelected.append(dictionari[i]);
			else letterSelected.append(" ");
		}
		if(dictionariPosition == dictionari.size()-1)
			App->renderer->Print(App->numericFontGreen, letterSelected.c_str(), (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 20) * 16, 0.f, true);
		else
			App->renderer->Print(App->numericFontRed, letterSelected.c_str(), (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 20) * 16, 0.f, true);
	}

	if(time <= 0 && finished == RUNNING) 
		App->renderer->Blit(gui, (SCREEN_WIDTH / 2) - gameOver.w/2, (SCREEN_HEIGHT / 3), &gameOver, 0.f);

	if (checkTime > 0) {
		if((int)checkTime % 2 == 0) App->renderer->Blit(gui, (int)((SCREEN_WIDTH / 2) - extendedPlay.w/2), (SCREEN_HEIGHT / 20) * 6, &extendedPlay, 0.f, false);
		App->renderer->Print(App->numericFontWhite, "LAPTIME", (SCREEN_WIDTH / 2) - (8*18) + 8, (SCREEN_HEIGHT / 20) * 7, 0.f, false);
		App->renderer->Print(App->numericFontYellow, getTimeFromFloat(lastLapTime).c_str(), (SCREEN_WIDTH / 2) + 16, (SCREEN_HEIGHT / 20) * 7, 0.f, false);
		App->renderer->Print(App->numericFontWhite, "BEST LAPTIME", (SCREEN_WIDTH / 2) - (12*18), (SCREEN_HEIGHT / 20) * 8, 0.f, false);
		App->renderer->Print(App->numericFontYellow, getTimeFromFloat(stageTimeSaved[stage-2]).c_str(), (SCREEN_WIDTH / 2) + 16, (SCREEN_HEIGHT / 20) * 8, 0.f, false);
	}

}


// Update: draw background
update_status ModuleSceneTrack::Update(const float deltaTime)
{
	if (time <= 0) {
		run = false;
		if (finished == RUNNING && timeGameOver <= 0) finished = BONUS;
		timeGameOver -= deltaTime;
	}

	if (biomSwap) swapBioma(deltaTime);

	if (run && finished == RUNNING) {
		time -= deltaTime;
		delayCheckPoint -= deltaTime;
		checkTime -= deltaTime;
		lapTime += deltaTime;
		totalTime += deltaTime;
		if (delayCheckPoint < 0) delayCheckPoint = 0;
		if (checkTime < 0) checkTime = 0;
		if (time < 0) time = 0;

		int segL = SEGL;
		//if (speed < MIN_SPEED*6) speed += acceleration*deltaTime*6;
		if (speed < MIN_SPEED) speed += acceleration*deltaTime;
		//Updates enemys position depends on the level
		for (unsigned int i = 0; i < enemys.size(); i++) {
			//Update enemys on advanced
			if (enemys[i]->posZ + 100 < pos / segL) {
				int randAdvance= (rand() % 200) + 100;
				enemys[i]->posZ = mostAdvancedEnemyZ + randAdvance;
				mostAdvancedEnemyZ += randAdvance;
			}
			if(enemys[i]->posZ < enemys[i]->posStopSprint && enemys[i]->posZ > FIRST_ROAD_STRIGHT) enemys[i]->posZ = (float)enemys[i]->posStopSprint;
			else enemys[i]->posZ += (enemys[i]->speed / segL) * deltaTime * 75;
		}
		mostAdvancedEnemyZ += (enemys[enemys.size()-1]->speed / segL) * deltaTime * 75;

		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		{
			if (speed < MAX_SPEED_NO_TURBO) speed += acceleration*deltaTime;
		}
		else {
			if(speed > MIN_SPEED) speed -= acceleration*deltaTime;
		}

		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		{
			if (speed > MIN_SPEED) speed -= acceleration*deltaTime;
			App->player->breaking = true;
		}
		else {
			App->player->breaking = false;
		}

		//Turn right and left
		if (App->player->colision == NOT_FALLING && (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT))
		{
			float moveX = (TRUN_CONST * deltaTime * 100.0f) / (speed * 0.01f);
			if (moveX > TRUN_CONST) moveX = TRUN_CONST;
			playerX += (int)moveX;
		}

		if (App->player->colision == NOT_FALLING && (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT))
		{
			float moveX = (TRUN_CONST * deltaTime * 100.0f) / (speed * 0.01f);
			if(moveX > TRUN_CONST) moveX = TRUN_CONST;
			playerX -= (int)moveX;
		}

		if ((App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT) && speed > MIN_VEL_TURBO)
		{
			App->player->turbo = true;
			if (speed < MAX_VEL_TURBO) speed += acceleration*deltaTime;
		}
		else {
			App->player->turbo = false;
			if (speed > MAX_SPEED_NO_TURBO) speed -= acceleration*deltaTime;
		}
		realPos += (int)(speed*deltaTime*75);
		if (realPos > 200) {
			pos += 200 * (realPos / segL);
			realPos -= 200 * (realPos / segL);
		}

		score += (int)((speed/10) * deltaTime * 10);
		
		//Move player to compensate the force of the curve
		if (!debugRoad) {
			int startPos = pos / SEGL;
			float currentCurve = lines[startPos%N].curve;
			if (currentCurve > 2.9) playerX -= (int)(CURVE_FORCE_3 * deltaTime * (speed / 3));
			else if (currentCurve > 1.9) playerX -= (int)(CURVE_FORCE_2 * deltaTime * (speed / 3));
			else if (currentCurve > 0.9) playerX -= (int)(CURVE_FORCE_1 * deltaTime * (speed / 3));
			else if (currentCurve < 0) {
				if (currentCurve > -1.1) playerX += (int)(CURVE_FORCE_1 * deltaTime * (speed / 3));
				else if (currentCurve > -2.1) playerX += (int)(CURVE_FORCE_2 * deltaTime * (speed / 3));
				else if (currentCurve > -3.1) playerX += (int)(CURVE_FORCE_3 * deltaTime * (speed / 3));
			}
		}

		//SwapDebugMode
		if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN) {
			debugMode = !debugMode;
			if (!debugMode) {
				debugRoad = false;
			}
		}
		if (debugMode && (App->input->GetKey(SDL_SCANCODE_T) == KEY_DOWN)) {
			time += 10;
		}
		if (debugMode && (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)) {
			debugRoad = !debugRoad;
		}
		if (debugMode && App->input->GetKey(SDL_SCANCODE_F) == KEY_DOWN && App->player->colision == NOT_FALLING)
		{
			App->player->colision = COLLISIONED;
			run = false;
		}
		if (debugMode && App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN) {
			App->player->Disable();
			timeBonus = 5;
			saveScore();
			App->audio->PauseMusic();
			App->fade->FadeToBlack((Module*)App->scene_menu_one, this);
		}
	}
	else if (finished == PUNTUATION) {
		swapLeter -= deltaTime;
		if (swapLeter <= 0) {
			if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
			{
				swapLeter = 0.2f;
				dictionariPosition++;
				if (dictionariPosition == dictionari.size())dictionariPosition = 0;
			}

			if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
			{
				swapLeter = 0.2f;
				dictionariPosition--;
				if (dictionariPosition < 0)dictionariPosition = dictionari.size() - 1;
			}
		}
		if (puntuationPoistion >= 8) dictionariPosition = 26;
		//Name completed return menu
		if ((App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN) && dictionariPosition == 26) {
				timeBonus = 5;
				saveScore();
				App->audio->PauseMusic();
				App->fade->FadeToBlack((Module*)App->scene_menu_one, this);
		}
		else if ((App->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN) && bestScores[puntuationPoistion].name.size() < 3) {
			bestScores[puntuationPoistion].name.append(dictionari[dictionariPosition]);
		}
	}
	//Print Track
	PrintTrack(deltaTime);

	//Print GUI
	PrintGui(deltaTime);

	return UPDATE_CONTINUE;
}

bool ModuleSceneTrack::TrentToN(int n, int &res, float deltaTime, float &animationTime) 
{
	animationTime += deltaTime;
	bool ret = false;
	if (animationTime > TIME_TO_SWAP) {
		if (res > n) {
			res--;
			ret = true;
		}
		else if (res < n) {
			res++;
			ret = true;
		}
		if (ret) animationTime = 0;
	}
	return ret;
}

void ModuleSceneTrack::swapBioma(float deltaTime)
{
	background = bioms[currentBiomId]->background;
	backgroundParalax = bioms[currentBiomId]->backgroundParalax;
	int swapFinished = 0;
	updateBiomTimer += deltaTime;
	biomSwapBackgroundHelper = false;
	if (updateBiomTimer > 0.005) {
		updateBiomTimer = 0;
		//Update R
		if (grass1.r < bioms[currentBiomId]->grass1.r) grass1.r++;
		else if (grass1.r > bioms[currentBiomId]->grass1.r) grass1.r--;
		else swapFinished++;
		if (grass2.r < bioms[currentBiomId]->grass2.r) grass2.r++;
		else if (grass2.r > bioms[currentBiomId]->grass2.r) grass2.r--;
		else swapFinished++;
		if (rumble1.r < bioms[currentBiomId]->rumble1.r) rumble1.r++;
		else if (rumble1.r > bioms[currentBiomId]->rumble1.r) rumble1.r--;
		else swapFinished++;
		if (rumble2.r < bioms[currentBiomId]->rumble2.r) rumble2.r++;
		else if (rumble2.r > bioms[currentBiomId]->rumble2.r) rumble2.r--;
		else swapFinished++;
		if (color_road1.r < bioms[currentBiomId]->color_road1.r) color_road1.r++;
		else if (color_road1.r > bioms[currentBiomId]->color_road1.r) color_road1.r--;
		else swapFinished++;
		if (color_road2.r < bioms[currentBiomId]->color_road2.r) color_road2.r++;
		else if (color_road2.r > bioms[currentBiomId]->color_road2.r) color_road2.r--;
		else swapFinished++;
		if (color_line1.r < bioms[currentBiomId]->color_line1.r) color_line1.r++;
		else if (color_line1.r > bioms[currentBiomId]->color_line1.r) color_line1.r--;
		else swapFinished++;
		if (color_line2.r < bioms[currentBiomId]->color_line2.r) color_line2.r++;
		else if (color_line2.r > bioms[currentBiomId]->color_line2.r) color_line2.r--;
		else swapFinished++;
		if (sky.r < bioms[currentBiomId]->sky.r) sky.r += 3;
		else if (sky.r > bioms[currentBiomId]->sky.r) sky.r -= 3;
		else swapFinished++;
		if (abs(sky.r - bioms[currentBiomId]->sky.r) < 5) 
			sky.r = bioms[currentBiomId]->sky.r;
		else biomSwapBackgroundHelper = true;
		
		//Update G
		if (grass1.g < bioms[currentBiomId]->grass1.g) grass1.g++;
		else if (grass1.g > bioms[currentBiomId]->grass1.g) grass1.g--;
		else swapFinished++;
		if (grass2.g < bioms[currentBiomId]->grass2.g) grass2.g++;
		else if (grass2.g > bioms[currentBiomId]->grass2.g) grass2.g--;
		else swapFinished++;
		if (rumble1.g < bioms[currentBiomId]->rumble1.g) rumble1.g++;
		else if (rumble1.g > bioms[currentBiomId]->rumble1.g) rumble1.g--;
		else swapFinished++;
		if (rumble2.g < bioms[currentBiomId]->rumble2.g) rumble2.g++;
		else if (rumble2.g > bioms[currentBiomId]->rumble2.g) rumble2.g--;
		else swapFinished++;
		if (color_road1.g < bioms[currentBiomId]->color_road1.g) color_road1.g++;
		else if (color_road1.g > bioms[currentBiomId]->color_road1.g) color_road1.g--;
		else swapFinished++;
		if (color_road2.g < bioms[currentBiomId]->color_road2.g) color_road2.g++;
		else if (color_road2.g > bioms[currentBiomId]->color_road2.g) color_road2.g--;
		else swapFinished++;
		if (color_line1.g < bioms[currentBiomId]->color_line1.g) color_line1.g++;
		else if (color_line1.g > bioms[currentBiomId]->color_line1.g) color_line1.g--;
		else swapFinished++;
		if (color_line2.g < bioms[currentBiomId]->color_line2.g) color_line2.g++;
		else if (color_line2.g > bioms[currentBiomId]->color_line2.g) color_line2.g--;
		else swapFinished++;
		if (sky.g < bioms[currentBiomId]->sky.g) sky.g += 3;
		else if (sky.g > bioms[currentBiomId]->sky.g) sky.g -= 3;
		else swapFinished++;
		if (abs(sky.g - bioms[currentBiomId]->sky.g) < 5) 
			sky.g = bioms[currentBiomId]->sky.g;
		else biomSwapBackgroundHelper = true;

		//Update B
		if (grass1.b < bioms[currentBiomId]->grass1.b) grass1.b++;
		else if (grass1.b > bioms[currentBiomId]->grass1.b) grass1.b--;
		else swapFinished++;
		if (grass2.b < bioms[currentBiomId]->grass2.b) grass2.b++;
		else if (grass2.b > bioms[currentBiomId]->grass2.b) grass2.b--;
		else swapFinished++;
		if (rumble1.b < bioms[currentBiomId]->rumble1.b) rumble1.b++;
		else if (rumble1.b > bioms[currentBiomId]->rumble1.b) rumble1.b--;
		else swapFinished++;
		if (rumble2.b < bioms[currentBiomId]->rumble2.b) rumble2.b++;
		else if (rumble2.b > bioms[currentBiomId]->rumble2.b) rumble2.b--;
		else swapFinished++;
		if (color_road1.b < bioms[currentBiomId]->color_road1.b) color_road1.b++;
		else if (color_road1.b > bioms[currentBiomId]->color_road1.b) color_road1.b--;
		else swapFinished++;
		if (color_road2.b < bioms[currentBiomId]->color_road2.b) color_road2.b++;
		else if (color_road2.b > bioms[currentBiomId]->color_road2.b) color_road2.b--;
		else swapFinished++;
		if (color_line1.b < bioms[currentBiomId]->color_line1.b) color_line1.b++;
		else if (color_line1.b > bioms[currentBiomId]->color_line1.b) color_line1.b--;
		else swapFinished++;
		if (color_line2.b < bioms[currentBiomId]->color_line2.b) color_line2.b++;
		else if (color_line2.b > bioms[currentBiomId]->color_line2.b) color_line2.b--;
		else swapFinished++;
		if (sky.b < bioms[currentBiomId]->sky.b) sky.b += 3;
		else if (sky.b > bioms[currentBiomId]->sky.b) sky.b -= 3;
		else swapFinished++;
		if (abs(sky.r - bioms[currentBiomId]->sky.r) < 5) 
			sky.r = bioms[currentBiomId]->sky.r;
		else biomSwapBackgroundHelper = true;
	}
	if (swapFinished == 27) biomSwap = false;
}

string ModuleSceneTrack::getTimeFromFloat(float time)
{
	string result;
	if (time > 60) {
		result = to_string((int)(time/60)).append("'");
		time -= 60 * ((int)(time / 60));
	}
	else result = "0'";
	result.append(to_string((int)time));
	result.append("\"");
	result.append(to_string((int)(time * 100) % 100));
	return result;
}

void ModuleSceneTrack::saveScore()
{
	//Record the times
	ofstream myScore;
	string input;
	myScore.open("level/africaStageTime.txt");

	myScore << to_string(stageTimeSaved.size()) << endl;
	for (unsigned int i = 0; i < stageTimeSaved.size(); i++) {
		myScore << to_string(stageTimeSaved[i]) << endl;
	}

	//Record scores
	ofstream myFinalScore;
	myFinalScore.open("level/africaBestScores.txt");
	for (unsigned int i = 0; i < bestScores.size(); i++) {
		myFinalScore << to_string(bestScores[i].score) << endl;
		myFinalScore << to_string(bestScores[i].stage) << endl;
		myFinalScore << bestScores[i].name << endl;
		myFinalScore << to_string(bestScores[i].time) << endl;
	}
}
