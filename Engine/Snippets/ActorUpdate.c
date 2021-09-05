void _UER_ActorUpdate(Gfx **display_list, NUContData gamepads[4]) 
{
	for (int i = 0; i < vector_size(_UER_Actors); i++)
	{
		Actor *curr = vector_get(_UER_Actors, i);

		if (curr->parent == NULL) CActor_Draw(curr, display_list);

		if (curr->update != NULL) curr->update(curr);

		if (curr->input != NULL) curr->input(curr, gamepads);
	}
}