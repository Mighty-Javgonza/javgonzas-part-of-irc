#ifndef MAIN_LOOP_HPP
# define MAIN_LOOP_HPP

void process_one_message_from_each_queue(Database &database, orchestator &orchest, ServerInfo &server_info);
void server_shutdown(Database *database, orchestator *orchest, ServerInfo *server_info);
void kill_zombies(Database &database, orchestator &orchest);

#endif
