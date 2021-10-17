#include <gtk/gtk.h>


static void send_refresh_signal(void)
{
	GdkEventClient ev;

	ev.type = GDK_CLIENT_EVENT;
	ev.send_event = TRUE;
	ev.window = NULL;
	ev.message_type = gdk_atom_intern("_GTK_READ_RCFILES", FALSE);
	ev.data_format = 8;

	gdk_event_send_clientmessage_toall((GdkEvent *)&ev);
}


int main(void)
{
	gtk_init(NULL, NULL);
	send_refresh_signal();
	return 0;
}
