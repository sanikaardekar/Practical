import java.util.HashSet;
import java.util.LinkedList;

import java.util.Queue;

class fifo {
	static int pageFaults(int incomingStream[], int n, int frames) {

		// System.out.println("Incoming \t Pages");

		HashSet s = new HashSet<>(frames);
		Queue queue = new LinkedList<>();

		int page_faults = 0;
		for (int i = 0; i < n; i++)

		{
			if (s.size() < frames)

			{
				if (!s.contains(incomingStream[i]))

				{

					s.add(incomingStream[i]);
					page_faults++;

					queue.add(incomingStream[i]);

				}

			} else

			{
				if (!s.contains(incomingStream[i]))

				{
					int val = (int) queue.peek();
					queue.poll();   //queue.poll()

					s.remove(val);

					s.add(incomingStream[i]);
					queue.add(incomingStream[i]);
					page_faults++;

				}

			}
			System.out.print(incomingStream[i] + "\t");

			System.out.print(queue + " \n");

		}
		return page_faults;

	}

	public static void main(String args[]) {
		int incomingStream[] = { 7, 0, 1, 2, 0, 3, 0, 3 };
		int frames = 3;

		int len = incomingStream.length;

		int pageFaults = pageFaults(incomingStream, len, frames);
		int hit = len - pageFaults;

		System.out.println("Page faults: " + pageFaults);

		System.out.println("Page fault Ratio: " + (double) pageFaults / len);
		System.out.println("Hits: " + hit);

		System.out.println("Hit Ratio : " + (double) hit / len);
	}
}
