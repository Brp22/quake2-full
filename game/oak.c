void SP_Oak(void)
{
	edict_t *newOak;
	vec3_t	spawn_origin, spawn_angles;

	// spawn the bot on a spawn spot
	newOak = G_Spawn();
	SelectSpawnPoint (spawn_origin, spawn_angles);
	VectorCopy (spawn_origin, newOak->s.origin);
	newOak->s.origin[2] += 1;	// make sure off ground
	
	newOak->classname = "bot";
	newOak->takedamage = DAMAGE_AIM;
	newOak->movetype = MOVETYPE_STEP;
	newOak->mass = 200;
	newOak->solid = SOLID_BBOX;
	newOak->deadflag = DEAD_NO;
	newOak->clipmask = MASK_PLAYERSOLID;
	newOak->model = "players/male/tris.md2";
	newOak->s.modelindex = 255;
	newOak->s.modelindex2 = 255;		// custom gun model
	newOak->s.frame = 0;
	newOak->waterlevel = 0;
	newOak->watertype = 0;
	newOak->health = 100;
	newOak->max_health = 100;
	newOak->gib_health = -40;

	// think functions
	newOak->pain = oak_pain;
	newOak->die = oak_die;

	VectorSet (newOak->mins, -16, -16, -24);
	VectorSet (newOak->maxs, 16, 16, 32);
	VectorClear (newOak->velocity);

	gi.linkentity (newOak);
	gi.bprintf (PRINT_HIGH, "A Oak bot has entered the game\n");

}