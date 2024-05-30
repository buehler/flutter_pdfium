import 'package:flutter/material.dart';

class UseCaseCard extends StatefulWidget {
  final String title;
  final String description;
  final VoidCallback onTap;
  final IconData icon;

  const UseCaseCard(
      {super.key,
      required this.icon,
      required this.title,
      required this.description,
      required this.onTap});

  @override
  State<UseCaseCard> createState() => _UseCaseCardState();
}

class _UseCaseCardState extends State<UseCaseCard> {
  var _hovered = false;

  @override
  Widget build(BuildContext context) => GestureDetector(
        onTap: widget.onTap,
        child: MouseRegion(
          onEnter: (event) => setState(() => _hovered = true),
          onExit: (event) => setState(() => _hovered = false),
          child: Card(
            elevation: _hovered ? 8 : 2,
            child: Padding(
              padding: const EdgeInsets.all(16),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Center(
                      child: Icon(widget.icon,
                          size: 36, color: Colors.deepOrange)),
                  const SizedBox(height: 16),
                  Center(
                      child: Text(widget.title,
                          style: Theme.of(context).textTheme.headlineSmall)),
                  const SizedBox(height: 8),
                  Text(
                    widget.description,
                    overflow: TextOverflow.ellipsis,
                    maxLines: 3,
                  ),
                ],
              ),
            ),
          ),
        ),
      );
}
